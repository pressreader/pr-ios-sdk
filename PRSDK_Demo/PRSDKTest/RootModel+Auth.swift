//
//  RootModel+Auth.swift
//  PRSDKTest
//
//  Created by Vitalii Hudenko on 24.11.2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

import Foundation
import PRUI

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
    
    var availableAuthOptions: [AuthData] {
        var cases = AuthData.allCases
        if let currentAuthData = self.authorizationData,
           let index = cases.firstIndex(where: { $0.id == currentAuthData.id })
        {
            cases.remove(at: index)
            cases.insert(currentAuthData, at: index)
        }
        
        return cases.filter { self.isAuthorizationEnabled(authData: $0) }
    }
    
    private(set) var authorizationData: AuthData? {
        get {
            if let rawData = UserDefaults.standard
                .dictionary(forKey: "PRSDKTestAuthData") as? [String: String],
                let authData = AuthData(rawValue: rawData)
            {
                return authData
            }
            
            if let token = UserDefaults.standard.string(forKey: "PRAuthToken") {
                UserDefaults.standard.setValue(nil, forKey: "PRAuthToken")
                let auth = AuthData.giftToken(token)
                self.authorizationData = auth
                
                return auth
            }
            
            return nil
        }
        set {
            UserDefaults.standard.set(newValue?.rawValue, forKey: "PRSDKTestAuthData")
            PRMainThreadAsync {
                self.delegate.reloadData()
            }
        }
    }
    
    // MARK: - Public Methods
    
    func canAuthorize(authData: AuthData) -> Bool {
        self.isReady && self.isAuthorizationEnabled(authData: authData)
    }
    
    func isAuthorizationEnabled(authData: AuthData) -> Bool {
        guard !self.isDismissed,
              !self.isLocalService
        else {
            return false
        }
        
        switch self.currentService {
        case Service.default:
            return authData.id == AuthData.giftToken("").id
        default:
            return authData.id == AuthData.externalAuthToken(token: "", provider: "").id
        }
    }
    
    func authorize(giftToken: String) async throws {
        guard let account,
              !giftToken.isEmpty
        else {
            throw ServiceError.missingParameter
        }
        
        try await account.authorize(token: giftToken)
        self.authorizationData = .giftToken(giftToken)
    }
    
    func authorizeWithExternalToken() async throws {
        guard let account else { return }
        
        let (token, provider) = try await self.generateExternalAuthTokenMock()
        try await account.authorize(externalToken: token, provider: provider)
        self.authorizationData = .externalAuthToken(token: token, provider: provider)
    }
        
    func deauthorize() async throws {
        try await self.account?.deauthorize()
        self.authorizationData = nil
    }

    // MARK: - Private Methods
    
    private func generateExternalAuthTokenMock() async throws -> (token: String, provider: String) {
        guard let mockURL = URL(string: "https://services.pressreader.com/test/pr-mock-auth-server/token?sub=00u-\(Int.random(in: 1...Int.max))&aud=test-aud&minutes=36000")
        else {
            throw ServiceError.noServiceUrlProvided
        }
        
        let (data, _) = try await URLSession.shared.data(from: mockURL)
        let json = try JSONSerialization.jsonObject(with: data) as? [String: String]
        guard let token = json?.nonEmptyString("token") else {
            throw ServiceError.unexpectedResponse
        }
        
        return (token, "pressreaderJwt")
    }
}
