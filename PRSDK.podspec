Pod::Spec.new do |spec|
  spec.name         = "PRSDK"
  spec.version      = "7.1.4"
  spec.summary      = "Pressreader SDK"
  spec.description  = "Set of PressReader frameworks."

  spec.homepage     = "https://www.pressreader.com"
  spec.license      = "MIT"
  spec.author             = { "PressReader" => "iphonesupport@support.pressreader.com" }
  spec.ios.deployment_target  = "15.0"
  spec.source       = { :git => "https://github.com/pressreader/pr-ios-sdk.git", :tag => spec.version.to_s }

  spec.resource  = "PRSDK/PressReaderResources.bundle"
  
  spec.vendored_frameworks = "PRSDK/PRCommands.xcframework", "PRSDK/PRAccessibility.xcframework", "PRSDK/PRAds.xcframework", "PRSDK/PRAlertKit.xcframework", "PRSDK/PRAnalytics.xcframework", "PRSDK/PRAPI.xcframework", "PRSDK/PRCatalogModel.xcframework", "PRSDK/PRConfiguration.xcframework", "PRSDK/PRCoreDataUtils.xcframework", "PRSDK/PRDIContainer.xcframework", "PRSDK/PRIAPReceipt.xcframework", "PRSDK/PRImageProcessing.xcframework", "PRSDK/PRLogKit.xcframework", "PRSDK/PRPromiseKit.xcframework", "PRSDK/PRProtocols.xcframework", "PRSDK/PRSmart.xcframework", "PRSDK/PRSyntacticSugar.xcframework", "PRSDK/PRThumbnail.xcframework", "PRSDK/PRUI.xcframework", "PRSDK/PRUIKit.xcframework", "PRSDK/PRUtils.xcframework", "PRSDK/GCDWebServers.xcframework", "PRSDK/HJCache.xcframework", "PRSDK/JSONKit.xcframework", "PRSDK/LTUpdate.xcframework", "PRSDK/MBProgressHUD.xcframework", "PRSDK/MTBlockTableView.xcframework", "PRSDK/OpenIDFA.xcframework", "PRSDK/StreamingKit.xcframework", "PRSDK/WKYTPlayerView.xcframework", "PRSDK/WYPopoverController.xcframework", "PRSDK/NetworkingKit.xcframework"

  spec.dependency "CocoaLumberjack"
  spec.dependency "SDWebImage"
  spec.dependency "FMDB"

end
