#
# Be sure to run `pod lib lint RKExpert_Foton.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'RKExpert_Foton'
  s.version          = '0.2.0'
  s.summary          = 'A short description of RKExpert_Foton.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://www.rokid.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '刘爽' => 'shuang.liu@rokid.com' }
  s.source           = { :git => 'https://github.com/rokid-cd/RKExpert_Foton.git', :tag => s.version.to_s }
  
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
    
  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.requires_arc = true

  s.libraries    = "stdc++"

  s.default_subspec = 'RKExpert_Foton'

  s.subspec 'RKExpert_Foton' do |ss|

    ss.vendored_frameworks = 'RKExpert_Foton/Classes/Frameworks/RokidSDK/*.framework'
    ss.source_files = 'RKExpert_Foton/Classes/Include/**/*'
    ss.resources = 'RKExpert_Foton/Assets/*.bundle'
    ss.dependency 'RKExpert_Foton/RokidReplayKit'
    
    ss.dependency "Moya", "~> 13.0.1"
    ss.dependency "HandyJSON", '~> 5.0.2'
    ss.dependency "Kingfisher", "~> 4.10.1"
    ss.dependency "SnapKit", "~> 4.2.0"
    ss.dependency "Then", "~> 2.7.0"
    ss.dependency 'IQKeyboardManager', '~> 6.5.6'
    ss.dependency "ReachabilitySwift", "~> 5.0.0"
    ss.dependency "PullToRefreshKit", "~> 0.8.8"
    ss.dependency "SCNLine", "~> 1.0"
    # QMUIKit  4.2.0 开始不再支持 iOS 9.0
    ss.dependency 'QMUIKit', '~> 4.1.3'

    ss.dependency 'RKBaseModule/RKFilePreview'
    ss.dependency "TZImagePickerController"
  end

  s.subspec 'RokidReplayKit' do |ss|
    ss.vendored_frameworks = 'RKExpert_Foton/Classes/Frameworks/RokidReplayKit/RokidReplayKit.framework'
  end
  
  
end
