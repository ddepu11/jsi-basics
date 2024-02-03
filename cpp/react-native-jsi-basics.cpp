#include "react-native-jsi-basics.h"
#include "iostream"

using namespace std;

void initializeJSIBasics(jsi::Runtime &runtime){
    
//  multiply function.
    auto multiplyLambda = [](jsi::Runtime &runtime,const jsi::Value &thisValue,const jsi::Value *args,size_t count)->jsi::Value{
        
        //  Throw an error
                // When you get more arguments then expected.
                if(count>2){
                    throw jsi::JSError(runtime, "Too many arguments!!!");
                }
                
                if(count<2){
                    throw jsi::JSError(runtime, "Please pass two arguments!!");
                }
                
        //        //  Cast to basic type
                if(!args[0].isNumber()){
                    throw jsi::JSError(runtime, "Argument 1 is not a number!");
                }
                
               //   Get js value as cpp value;
                double arg1 = args[0].asNumber();
//              int intArg2 = (int)arg1;
        
                if(!args[1].isNumber()){
                    throw jsi::JSError(runtime, "Argument 2 is not a number!");
                }
              
                double arg2 = args[1].asNumber();
        //        int intArg2 = (int)arg2;
                
                
                return jsi::Value(arg1*arg2);
    
    };
    jsi::Function multiply = jsi::Function::createFromHostFunction(runtime, jsi::PropNameID::forAscii(runtime, "multiply"), 0, std::move(multiplyLambda));
    
//    #################### Experiments with Function's Arguments ########################
    
    auto lambdaExperimentFunc = [](jsi::Runtime &runtime,const jsi::Value &thisValue, const jsi::Value *args, size_t count)->jsi::Value {
            
        if(count<1){
            throw  jsi::JSError(runtime, "Please pass atleast one argument!!!");
        }

//      Casting to different types, and returning those values
        
//      String
//        string stringArgs = args[0].asString(runtime).utf8(runtime);
//        return jsi::String::createFromUtf8(runtime, stringArgs);
        
//      Object
//        jsi::Object objectArg = args[0].asObject(runtime);
//        objectArg.setProperty(runtime, "isDisabled", jsi::Value(false));
//        objectArg.setProperty(runtime, "index", 2);
//        
//        return objectArg;
        
//      Array (in js array are just an object)
//        jsi::Array arrayArg = args[0].asObject(runtime).asArray(runtime);
//        auto anElemet = arrayArg.getValueAtIndex(runtime, 4);
//        int arraySize = (int)arrayArg.size(runtime);
//
//        jsi::Object arrayInfoObject = jsi::Object(runtime);
//        arrayInfoObject.setProperty(runtime, "arrayItself", arrayArg);
//        arrayInfoObject.setProperty(runtime, "anElementOfArray", anElemet);
//        arrayInfoObject.setProperty(runtime, "arraySize", arraySize);
//
//        return arrayInfoObject;
        
//      Null value
        
//        jsi::Value nullVal = jsi::Value::null();
//        OR
//        jsi::Value nullVal = jsi::Value(nullptr);
        
//        return nullVal;
        
//      Undefined
//        jsi::Value undefinedValue = jsi::Value::undefined();
//        return undefinedValue;
//     ################################### CASTINGS ENDS ########################################
        
//      Create an Array
        
//        jsi::Array anArray = jsi::Array(runtime, 7);
//        
//        anArray.setValueAtIndex(runtime, 0, jsi::String::createFromUtf8(runtime, "Mohan"));
//        anArray.setValueAtIndex(runtime, 1, jsi::String::createFromUtf8(runtime, "Rohan"));
//        anArray.setValueAtIndex(runtime, 2, jsi::String::createFromUtf8(runtime, "Gopal"));
//        anArray.setValueAtIndex(runtime, 3, jsi::Value::undefined());
//        anArray.setValueAtIndex(runtime, 4, jsi::Value::null());
//        anArray.setValueAtIndex(runtime, 5, jsi::Object(runtime));
//        anArray.setValueAtIndex(runtime, 6, jsi::Array(runtime,0));
//
//        return anArray;
        
//      Create an object
        
          jsi::Object resObj = jsi::Object(runtime);
        
          resObj.setProperty(runtime, "isSelectable", jsi::Value(true));
          resObj.setProperty(runtime, "innerObj", jsi::Object(runtime));
          resObj.setProperty(runtime, "address", jsi::String::createFromUtf8(runtime, "H No 420, NS Palya, 3rd Main."));
        
          return resObj;
        
        
    };
    
    jsi::Function experimentWithFuntion = jsi::Function::createFromHostFunction(runtime, jsi::PropNameID::forAscii(runtime, "experimentFunction"), 1, std::move(lambdaExperimentFunc));
    
    
//  Adding JSI function to the JSI module object.
    jsi::Object module = jsi::Object(runtime);
    module.setProperty(runtime, "jsiMultiply", std::move(multiply));
    module.setProperty(runtime, "experimentWithFuntion", std::move(experimentWithFuntion));
    
//  Register the JSI module object to the JS Runtime(global) and name it "__JsiBasics"
    runtime.global().setProperty(runtime, "__JsiBasics", std::move(module));
    
};
