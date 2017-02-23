Pod::Spec.new do |s|
  s.name         = "libtangoflaresdk"
  s.version      = "1.1.3"
  s.summary      = "libtangoflaresdk for iOS"
  s.description  = "libtangoflaresdk for iOS (armv7,arm64,i386,x86_64)"
  s.homepage     = "http://github.com/"
  s.license      = { :type => 'LICENSE-APACHE', :file => 'LICENSE.txt' }
  s.source       = { :git => "https://github.com/atomnode/libtangoflaresdk.git", :tag => "#{s.version}" }
  s.author             = { "How Tah Lun" => "" }  
  s.platform          = :ios, '9.0'
  s.ios.deployment_target = '9.0'
  s.ios.source_files        = 'include/TangoFlareSDK/**/*.h'
  s.ios.public_header_files = 'include/TangoFlareSDK/**/*.h'
  #s.ios.header_dir          = 'libtangoflaresdk'
  s.resource  = 'include/TangoFlareSDK/**/*.bundle' 
  s.ios.preserve_paths      = 'lib-ios/libtangoflaresdk.a'
  s.ios.vendored_libraries  = 'lib-ios/libtangoflaresdk.a'
  s.dependency "AFNetworking", '~> 3.0'
  s.dependency "JSONModel", '~> 1.3.0'
  s.dependency "Valet", '~> 2.2.2'
  s.dependency "RMQClient", '~> 0.9'
end
