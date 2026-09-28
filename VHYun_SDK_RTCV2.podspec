Pod::Spec.new do |s|
  s.name          = "VHYun_SDK_RTCV2"
  s.version       = "3.2.9"
  s.summary       = "VHall iOS SDK #{s.name.to_s}"
  s.homepage     = 'https://www.vhall.com'
  s.author       = { "yu.qiu" => "415657636@qq.com" }
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.source          = { :git => "https://github.com/vhall/VHYun_SDK_RTCV2_iOS.git", :tag => s.version.to_s}
  s.requires_arc    = true
  s.platform        = :ios, '9.0'
  s.module_name     = "#{s.name.to_s}"
  s.vendored_frameworks = 'VHYunFrameworks/VHRTCV2.framework'
  s.dependency 'VHCore','>=2.3.8'
  s.dependency 'TXLiteAVSDK_Professional'
end
