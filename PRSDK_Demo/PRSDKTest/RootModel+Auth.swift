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
    
    enum AuthData: RawRepresentable {
        case giftToken(String)
        case externalAuthToken(token: String, provider: String, userId: String?)
        
        // MARK: - RawRepresentable
        
        var rawValue: [String: String] {
            switch self {
            case .giftToken(let token):
                return ["type": "giftToken",
                        "token": token]
            case .externalAuthToken(let token, let provider, let userId):
                var data = ["type": "externalToken",
                            "token": token,
                            "provider": provider]
                userId.map { data["userId"] = $0 }
                
                return data
            }
        }
        
        init?(rawValue: [String : String]) {
            switch rawValue["type"] {
            case "giftToken":
                guard let auth = rawValue["token"]
                    .map({ AuthData.giftToken($0) })
                else {
                    return nil
                }
                
                self = auth
                
            case "externalToken":
                guard let auth = lift(rawValue["token"], rawValue["provider"])
                    .map({ AuthData.externalAuthToken(token: $0,
                                                      provider: $1,
                                                      userId: rawValue["userId"]) })
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
            let rawData = UserDefaults.standard
                .dictionary(forKey: "PRSDKTestAuthData") as? [String: String]
            let currentService = self.currentService
            let authType = rawData
                .flatMap {
                    let data = AuthData(rawValue: $0)
                    switch data {
                    case .giftToken where currentService == Service.default:
                        return data
                    case .externalAuthToken where currentService != Service.default:
                        return data
                    default: return nil
                    }
                }
            ?? {
                var newData: AuthData!
                switch currentService {
                case Service.default:
                    newData = .giftToken("")
                default:
                    newData = .externalAuthToken(token: "", provider: "", userId: nil)
                }
                
                self.authorizationData = newData
                
                return newData
            }()
            
            return authType
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: "PRSDKTestAuthData")
        }
    }
    
    var canAuthorize: Bool {
        self.isReady
    }
    
    var isTokenGenerationAvailable: Bool {
        self.currentService != Service.default
        && self.isServiceSelectionEnabled
    }

    // MARK: - Public Methods
    
    func authorize() async throws {
        guard let account else { return }
        
        switch self.authorizationData {
        case .giftToken(let token):
            try await account.authorize(token: token)
        case .externalAuthToken(let token, let provider, _):
            try await account.authorize(externalToken: token, provider: provider)
        }
    }
    
    func deauthorize() async throws {
        try await self.account?.deauthorize()
    }
    
    func generateExternalAuthTokenMock(userId: String?) async throws {
        let userId = userId
            .flatMap { Int($0) }
        ?? Int.random(in: 1...Int.max)
        
        guard let mockURL = URL(
            string: "https://services.pressreader.com/test/pr-mock-auth-server/token?sub=00u-\(userId)&aud=test-aud&minutes=36000"
        )
        else {
            throw ServiceError.noServiceUrlProvided
        }
        
        let (data, _) = try await URLSession.shared.data(from: mockURL)
        let json = try JSONSerialization.jsonObject(with: data) as? [String: String]
        guard let token = json?.nonEmptyString("token") else {
            throw ServiceError.unexpectedResponse
        }
        
        self.authorizationData = .externalAuthToken(token: token,
                                                    provider: "pressreaderJwt",
                                                    userId: String(userId))
    }
}
