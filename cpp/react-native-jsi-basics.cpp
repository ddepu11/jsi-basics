#include "react-native-jsi-basics.h"
#include "iostream"
#include "MyObject.h"

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
    
    
    //  Adding JSI Host functions to the JSI module object.
    jsi::Object module = jsi::Object(runtime);
    module.setProperty(runtime, "jsiMultiply", std::move(multiply));
    module.setProperty(runtime, "experimentWithFuntion", std::move(experimentWithFuntion));
    
    
    auto sharedHostObject = std::make_shared<dep::MyObject>();
    //  Adding JSI Host Object to this JSI module object.
    module.setProperty(runtime, "MyObject", jsi::Object::createFromHostObject(runtime, sharedHostObject));
    
    //  Register the JSI module object to the JS Runtime(global) and name it "__JsiBasics"
    runtime.global().setProperty(runtime, "__JsiBasics", std::move(module));
};

//  Some Explanations

//  std::move
//  Moving Ownership, Not Copying:
//  std::move is a utility function that efficiently transfers ownership of objects, rather than creating copies
//  Avoiding Unnecessary Copies: By moving the objects instead of copying them, you can potentially avoid the overhead of creating new copies in memory, which can improve performance.
//  It's often used when you no longer need the original variable and want to transfer its resources efficiently.
      
    
//  use of utf8 and createFromUtf8
//  Interoperability and Standardization:
    
//  Cross-Platform Compatibility: UTF-8 is the most widely supported character encoding across various platforms and programming languages. By converting to UTF-8, you ensure that the string can be correctly interpreted and used regardless of the underlying system or language.

//  JavaScript String Standard: JavaScript strings are inherently UTF-16 encoded, but UTF-8 is the preferred encoding for text-based data exchange due to its efficiency and compatibility. Converting to UTF-8 aligns with JavaScript's string handling conventions.

//  createFromUtf8
//  It ensures that text data is correctly interpreted and represented as strings within the JavaScript environment, enabling seamless interaction between native and JavaScript code.

//  make_shared
    
//    1. Purpose:
//
//    It's a function template in C++ that creates a new std::shared_ptr object, which is a smart pointer that manages the lifetime of a dynamically allocated object.
//    2. Key Advantages:
//
//    Automatic Memory Management: The std::shared_ptr keeps track of how many references to the object exist and automatically deallocates the object when the last reference goes out of scope, preventing memory leaks.
//    Efficient Single Allocation: std::make_shared often performs a single memory allocation for both the object itself and the associated control block, potentially improving performance over separate calls to new and std::shared_ptr.
//    Exception Safety: It ensures that if an exception is thrown during object construction, no memory leaks occur.

