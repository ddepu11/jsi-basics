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
    
    
    auto lambdaExperimentFunc = [](jsi::Runtime &runtime,const jsi::Value &thisValue, const jsi::Value *args, size_t count)->jsi::Value {
            
        if(count<1){
            throw  jsi::JSError(runtime, "Please pass atleast one argument!!!");
        }
            
        
        
        
        
        return jsi::Value(2);
    };
    jsi::Function experimentWithFuntion = jsi::Function::createFromHostFunction(runtime, jsi::PropNameID::forAscii(runtime, "experimentFunction"), 1, std::move(lambdaExperimentFunc));
    
    
    jsi::Object module = jsi::Object(runtime);
    module.setProperty(runtime, "jsiMultiply", std::move(multiply));
    module.setProperty(runtime, "experimentWithFuntion", std::move(experimentWithFuntion));
    
    runtime.global().setProperty(runtime, "__JsiBasics", std::move(module));
    
};
