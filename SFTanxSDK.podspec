Pod::Spec.new do |s|
    s.name             = 'SFTanxSDK'
    s.version          = '3.4.0.0'
    s.summary          = 'SFTanxSDK'

    s.description      = <<-DESC
            'SFTanxSDK is a AD SDK'
                       DESC

    s.homepage         = 'https://github.com/xiaofu666/TanxSDK'
    s.license      = { :type => "MIT", :file => "LICENSE" }
    s.author       = { "小富" => "3290235031@qq.com" }
    s.source = { :http => "https://github.com/xiaofu666/TanxSDK/releases/download/#{s.version}/TanxSDK.zip" }

    s.platform     = :ios, "9.0"
    
    s.frameworks = 'AssetsLibrary', 'MapKit', 'JavaScriptCore', 'StoreKit', 'MobileCoreServices', 'WebKit', 'MediaPlayer', 'CoreMedia', 'AVFoundation', 'CoreLocation', 'CoreTelephony', 'SystemConfiguration', 'AdSupport', 'CoreMotion', 'Security', 'QuartzCore', 'CoreGraphics', 'SafariServices', 'UIKit', 'Foundation', 'AppTrackingTransparency', 'DeviceCheck'
    s.libraries = 'c++', 'c++abi', 'resolv', 'xml2', 'bz2', 'z', 'iconv', 'sqlite3'

    s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC" }
    s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 arm64' }

    s.vendored_frameworks = 'TanxSDK/TanxSDK.framework', 'TanxSDK/TNXASDK.framework'
    s.resource = 'TanxSDK/TanxID.bundle'
end
