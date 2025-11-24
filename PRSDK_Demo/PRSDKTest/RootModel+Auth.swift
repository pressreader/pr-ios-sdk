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
    
    enum AuthData: RawRepresentable {
        case giftToken(String)
        case externalAuthToken(token: String, provider: String)
                
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
    
    var isAuthEnabled: Bool {
        !self.isDismissed && !self.isLocalService
    }

    var canAuthorise: Bool {
        self.isReady
    }

    var authData: AuthData {
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
                self.authData = auth
                
                return auth
            }
            
            return .giftToken("")
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: "PRSDKTestAuthData")
        }
    }
    
    // MARK: - Public Methods
    
    @MainActor
    func authorize() async throws {
        guard let account else { return }
        
        switch self.authData {
        case .giftToken(let token):
            guard !token.isEmpty else {
                throw ServiceError.missingParameter
            }
            
            try await account.authorize(token: token)
        case .externalAuthToken(let token, let provider):
            guard !token.isEmpty, !provider.isEmpty else {
                throw ServiceError.missingParameter
            }
            
            try await account.authorize(externalToken: token,
                                        provider: provider)
        }
    }
    
    func deauthorize() async throws {
        try await self.account?.deauthorize()
    }

    func generateExternalAuthTokenMock() async throws -> AuthData {
        guard self.currentService == .singleTitleAndFeedBE else {
            throw ServiceError.unknown
        }
        
        guard let mockURL = URL(string: "https://services.pressreader.com/test/pr-mock-auth-server/token?sub=00u-\(Int.random(in: 1...Int.max))&aud=test-aud&minutes=36000")
        else {
            throw ServiceError.noServiceUrlProvided
        }
        
        let (data, _) = try await URLSession.shared.data(from: mockURL)
        let json = try JSONSerialization.jsonObject(with: data) as? [String: String]
        guard let token = json?.nonEmptyString("token") else {
            throw ServiceError.unexpectedResponse
        }
        
        return .externalAuthToken(token: token, provider: "pressreaderJwt")
    }
}
