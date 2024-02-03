//
//  MyObject.cpp
//  react-native-jsi-basics
//
//  Created by Deepanshu Tiwari on 2/4/24.
//

#include "MyObject.h"


namespace dep {

    namespace jsi = facebook::jsi;


    jsi::Value MyObject::doSomeThing(jsi::Runtime &runtime){
        jsi::Object newObj = jsi::Object(runtime);
                
        newObj.setProperty(runtime, "name", jsi::String::createFromUtf8(runtime, "mohan"));
        newObj.setProperty(runtime, "lastName", jsi::Value::undefined());
                
        newObj.setProperty(runtime, "email", jsi::String::createFromUtf8(runtime, "mohan11@gmail.com"));
                
        newObj.setProperty(runtime, "isAvailable", jsi::Value(false));
                
        return newObj;
    };


    jsi::Value MyObject::get(jsi::Runtime &runtime, const jsi::PropNameID &propName){
        
        std::string newPropName = propName.utf8(runtime);
        
        if(newPropName == "doSomeThing"){
            return this -> doSomeThing(runtime);
        }
        
        if(newPropName == "stringArg"){
            return jsi::String::createFromAscii(runtime, this -> stringArg);
        }
        
        return {};
    };


    void MyObject::set(jsi::Runtime &runtime, const jsi::PropNameID &propName, const jsi::Value &value){
        std::string newPropName = propName.utf8(runtime);
        
        if(newPropName == "stringArg"){
            this -> stringArg = value.asString(runtime).utf8(runtime);
        }
        
    };

    std::vector<jsi::PropNameID> MyObject::getPropertyNames(jsi::Runtime &runtime){
        std::vector<jsi::PropNameID> properties;
        
        properties.push_back(jsi::PropNameID::forUtf8(runtime,std::string("stringArg")));
        properties.push_back(jsi::PropNameID::forUtf8(runtime,std::string("doSomeThing")));
        
        return properties;
    }
};


// forUtf8
// It internally converts the string to the appropriate representation for property name identification.
// It ensures consistent handling of property names across different language contexts and potentially optimizes property access operations.
// It's essential for bridging between native C++ string types and JavaScript property names within JSI.
