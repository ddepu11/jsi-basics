#ifdef __cplusplus
#import "react-native-jsi-basics.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNJsiBasicsSpec.h"

@interface JsiBasics : NSObject <NativeJsiBasicsSpec>
#else
#import <React/RCTBridgeModule.h>

@interface JsiBasics : NSObject <RCTBridgeModule>
#endif

@end
