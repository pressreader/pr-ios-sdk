Pod::Spec.new do |spec|
  spec.name         = "PRSDK"
  spec.version      = "8.3"
  spec.summary      = "Pressreader SDK"
  spec.description  = "Set of PressReader frameworks."

  spec.homepage     = "https://www.pressreader.com"
  spec.license      = "MIT"
  spec.author             = { "PressReader" => "iphonesupport@support.pressreader.com" }
  spec.ios.deployment_target  = "17.0"
  spec.source       = { :git => "https://github.com/pressreader/pr-ios-sdk.git", :tag => spec.version.to_s }
  
  spec.vendored_frameworks = "PRSDK/PRAccessibility.xcframework", "PRSDK/PRAds.xcframework", "PRSDK/PRAlertKit.xcframework", "PRSDK/PRAnalytics.xcframework", "PRSDK/PRAPI.xcframework", "PRSDK/PRCatalogModel.xcframework", "PRSDK/PRCommands.xcframework", "PRSDK/PRConfiguration.xcframework", "PRSDK/PRCoreDataUtils.xcframework", "PRSDK/PRDIContainer.xcframework", "PRSDK/PRIAPReceipt.xcframework", "PRSDK/PRImageProcessing.xcframework", "PRSDK/PRLogKit.xcframework", "PRSDK/PRPromiseKit.xcframework", "PRSDK/PRSmart.xcframework", "PRSDK/PRSyntacticSugar.xcframework", "PRSDK/PRThumbnail.xcframework", "PRSDK/PRUI.xcframework", "PRSDK/PRUIKit.xcframework", "PRSDK/PRUtils.xcframework", "PRSDK/GCDWebServers.xcframework", "PRSDK/HJCache.xcframework", "PRSDK/JSONKit.xcframework", "PRSDK/LTUpdate.xcframework", "PRSDK/MBProgressHUD.xcframework", "PRSDK/OpenIDFA.xcframework", "PRSDK/StreamingKit.xcframework", "PRSDK/WKYTPlayerView.xcframework", "PRSDK/WYPopoverController.xcframework", "PRSDK/NetworkingKit.xcframework", "PRSDK/FlowPubSDK.xcframework", "PRSDK/PREPubReader.xcframework"

  spec.dependency "CocoaLumberjack"
  spec.dependency "SDWebImage"
  spec.dependency "FMDB"

end
