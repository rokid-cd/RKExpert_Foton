#
# Be sure to run `pod lib lint RokidSDK_Foton_iOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'RokidRASDK'
  s.version          = '1.1.1'
  s.summary          = 'A short description of RokidRASDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = '33333'

  s.homepage         = 'https://github.com/yangyeda/RokidSDK_Foton_iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '' => '' }
  s.source           = { :git => 'https://github.com/yangyeda/RokidSDK_Foton_iOS.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.vendored_frameworks = 'Framework/*.framework'
  s.resources = 'Resource/*.bundle'

  s.ios.deployment_target = '9.0'

  s.requires_arc = true
  
  #spec.dependency "Moya", "~> 13.0.1"
  s.dependency "Kingfisher", "~> 4.10.1"
  #spec.dependency "HandyJSON", '~> 5.0.2'
  s.dependency "SnapKit", "~> 4.2.0"
  s.dependency "Then", "~> 2.7.0"
  s.dependency "IQKeyboardManager", "~> 6.5.6"
  s.dependency "TZImagePickerController"
  s.dependency "AFNetworking"
  s.dependency "SDWebImage", "4.4.8"
  s.dependency "Masonry"
  s.dependency "MJRefresh"
  s.dependency "JXCategoryView"
  s.dependency "DZNEmptyDataSet"
  s.dependency "MJExtension"
  s.dependency "TZImagePickerController"
  s.dependency "ReactiveObjC"
  s.dependency "SVProgressHUD"
  s.dependency "ZFPlayer", "~> 4.1.3"
  s.dependency "ZFPlayer/ControlView", "~> 4.1.3"
  s.dependency "ZFPlayer/ijkplayer", "~> 4.1.3"
  s.dependency "ZFPlayer/AVPlayer", "~> 4.1.3"

  s.dependency "Toast"
  s.dependency 'WSLWaterFlowLayout','>= 1.0.1'
  s.dependency "WMPageController", '~> 2.5.2'
  s.dependency 'Popover.OC', '~> 2.2'

#  s.dependency 'YBImageBrowser/NOSD' # iOS 图片浏览器 (支持视频)
#  s.dependency 'YBImageBrowser/VideoNOSD'

  # s.resource_bundles = {
  #   'RokidSDK_Foton_iOS' => ['RokidSDK_Foton_iOS/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  
 

end
