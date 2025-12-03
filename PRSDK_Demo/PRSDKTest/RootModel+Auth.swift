//
//  RootModel+Auth.swift
//  PRSDKTest
//
//  Created by Vitalii Hudenko on 24.11.2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

import Foundation
import PRUI
import PRLogKit

extension RootModel {
    
    // MARK: - Nested Types
    
    enum AuthData: RawRepresentable, CaseIterable, Identifiable {
        case giftToken(String)
        case externalAuthToken(token: String, provider: String)
        
        // MARK: - CaseIterable
        
        static let allCases = [AuthData.giftToken(""),
                               .externalAuthToken(token: "", provider: "")]
        
        // MARK: - Identifiable
        
        var id: String {
            self.rawValue.string("type")!
        }
        
        // MARK: - RawRepresentable
        
        var rawValue: [String: String] {
            switch self {
            case .giftToken(let token):
                ["type": "giftToken",
                 "token": token]
            case .externalAuthToken(let token, let provider):
                ["type": "externalToken",
                 "token": token,
                 "provider": provider]
            }
        }
        
        init?(rawValue: [String : String]) {
            guard let type = rawValue["type"] else {
                return nil
            }
            
            switch type {
            case "giftToken":
                guard let auth = rawValue["token"]
                    .map({ AuthData.giftToken($0) })
                else {
                    return nil
                }
                
                self = auth
                
            case "externalToken":
                guard let auth = lift(rawValue["token"], rawValue["provider"])
                    .map({ AuthData.externalAuthToken(token: $0, provider: $1) })
                else {
                    return nil
                }
                
                self = auth
                
            default:
                return nil
            }
        }
    }
    
    // MARK: - Public Properties
    
    var isAuthorizationEnabled: Bool {
        !self.isDismissed && !self.isLocalService
    }
    
    var authorizationData: AuthData {
        get {
            var storedData: AuthData?
            if let rawData = UserDefaults.standard
                .dictionary(forKey: "PRSDKTestAuthData") as? [String: String],
                let authData = AuthData(rawValue: rawData),
               self.isAuthorizationEnabled(authData: authData)
            {
                storedData = authData
            }
            
            if let token = UserDefaults.standard.string(forKey: "PRAuthToken") {
                UserDefaults.standard.setValue(nil, forKey: "PRAuthToken")
                let auth = AuthData.giftToken(token)
                self.authorizationData = auth
                
                if self.isAuthorizationEnabled(authData: auth) {
                    storedData = auth
                }
            }
            
            if let storedData {
                return storedData
            }
            
            let newData = AuthData.allCases
                .first(where: { self.isAuthorizationEnabled(authData: $0) })
            ?? {
                PRLog.debugCrash("No valid authorization data available")
                
                return AuthData.giftToken("")
            }()
            
            self.authorizationData = newData
            
            return newData
            
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: "PRSDKTestAuthData")
            PRMainThreadAsync {
                self.delegate.reloadData()
            }
        }
    }
    
    var canAuthorize: Bool {
        self.isReady && self.isAuthorizationEnabled(authData: self.authorizationData)
    }

    // MARK: - Public Methods
    
    func authorize() async throws {
        guard let account else { return }
        
        switch self.authorizationData {
        case .giftToken(let token):
            try await account.authorize(token: token)
        case .externalAuthToken(let token, let provider):
            try await account.authorize(externalToken: token, provider: provider)
        }
    }
    
    func deauthorize() async throws {
        try await self.account?.deauthorize()
    }
    
    func generateExternalAuthTokenMock() async throws {
        guard let mockURL = URL(string: "https://services.pressreader.com/test/pr-mock-auth-server/token?sub=00u-\(Int.random(in: 1...Int.max))&aud=test-aud&minutes=36000")
        else {
            throw ServiceError.noServiceUrlProvided
        }
        
        let (data, _) = try await URLSession.shared.data(from: mockURL)
        let json = try JSONSerialization.jsonObject(with: data) as? [String: String]
        guard let token = json?.nonEmptyString("token") else {
            throw ServiceError.unexpectedResponse
        }
        
        self.authorizationData = .externalAuthToken(token: token, provider: "pressreaderJwt")
    }
    
    // MARK: - Private Methods
    
    private func isAuthorizationEnabled(authData: AuthData) -> Bool {
        guard self.isAuthorizationEnabled else {
            return false
        }
        
        switch self.currentService {
        case Service.default:
            return authData.id == AuthData.giftToken("").id
        default:
            return authData.id == AuthData.externalAuthToken(token: "", provider: "").id
        }
    }

}
