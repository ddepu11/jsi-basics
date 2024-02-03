#import "JsiBasics.h"
#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

@implementation JsiBasics

// Module name JsiBasics
// Declares the class as a React Native module named JsiBasics
RCT_EXPORT_MODULE(JsiBasics)

using namespace facebook;

// This install func is available to JS side to be called.
// ex: JsiBasics.install()
RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install) {
    NSLog(@"Installing JSI Examples....");
    
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;

    if (cxxBridge == nil) {
        return @false;
    }

    auto jsiRuntime = (jsi::Runtime*)cxxBridge.runtime;

    if (jsiRuntime == nil) {
        return @false;
    }

    auto& runtime = *jsiRuntime;

    initializeJSIBasics(runtime);
    
    NSLog(@"Installed JSI Examples :) ");

    return @true;
}

@end
