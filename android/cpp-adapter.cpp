#include <jni.h>
#include "react-native-jsi-basics.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_jsibasics_JsiBasicsModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return jsibasics::multiply(a, b);
}
