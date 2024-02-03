//
//  MyObject.h
//  react-native-jsi-basics
//
//  Created by Deepanshu Tiwari on 2/4/24.
//

#ifndef MyObject_h
#define MyObject_h

#include <stdio.h>
#include "jsi/jsi.h"

namespace dep {
  
  namespace jsi = facebook::jsi;
  
  class JSI_EXPORT MyObject : public jsi::HostObject {
    
  public:
      std::string stringArg = "Initial string value!";
      
      jsi::Value doSomeThing(jsi::Runtime &runtime);
      
      jsi::Value get(jsi::Runtime &runtime, const jsi::PropNameID &propName);
    
      void set(jsi::Runtime &runtime,const jsi::PropNameID &propName,const jsi::Value &value);
      
//    vector is like an array, getPropertyNames returns vector of PropNameID
      std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime &runtime);
  };

};

#endif /* MyObject_hpp */
