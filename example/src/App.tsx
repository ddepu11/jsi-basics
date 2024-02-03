import * as React from 'react';

import {
  StyleSheet,
  View,
  Text,
  SafeAreaView,
  Pressable,
  Alert,
} from 'react-native';
import { JSIBasics } from 'react-native-jsi-basics';

const result = JSIBasics.jsiMultiply(40, 5);

export default function App() {
  const { experimentWithFuntion, MyObject } = JSIBasics;

  // String
  // const funcExpResult = experimentWithFuntion('Facebook');

  // Object
  // const funcExpResult = experimentWithFuntion({
  //   width: '100px',
  //   comName: 'Input',
  //   isDisabled: true,
  //   index: 0,
  // });

  // Array
  // const funcExpResult = experimentWithFuntion([
  //   'James',
  //   false,
  //   undefined,
  //   null,
  //   { name: 'Mohan' },
  //   ['Rohan', 'Ali'],
  //   1,
  // ]);

  // null, gives tyoeof as Object
  // const funcExpResult =
  //   experimentWithFuntion('') === null ? 'null' : 'not-null';

  // undefined, gives tyoeof as undefined
  // const funcExpResult =
  //   experimentWithFuntion('') === undefined ? 'undefined' : 'not-undefined';

  // Returns an Array, typeof array is an object
  // const funcExpResult = experimentWithFuntion('');

  // Returns an Object, typeof array is an object
  const funcExpResult = experimentWithFuntion('');

  console.log('funcExpResult: ', funcExpResult);

  return (
    <SafeAreaView style={styles.safeAreaView}>
      <View style={styles.container}>
        <Text style={styles.result}>Multiplication Res: {result}</Text>

        <View style={styles.devider} />

        {/* <Text style={styles.result}>Func Experiments: {funcExpResult}</Text> */}
        <Text style={styles.result}>Type: {typeof funcExpResult}</Text>

        <View style={styles.devider} />

        <Pressable
          style={styles.button}
          onPress={() => {
            Alert.alert(MyObject.stringArg);
          }}
        >
          <Text style={styles.buttonText}>Get stringArg initial value</Text>
        </Pressable>

        <View style={styles.devider} />

        <Pressable
          style={styles.button}
          onPress={() => {
            MyObject.stringArg = 'A new Value!!!';
            Alert.alert('Set New Value! to MyObject.stringArg prop!');
          }}
        >
          <Text style={styles.buttonText}>Set stringArg</Text>
        </Pressable>

        <View style={styles.devider} />

        <Pressable
          style={styles.button}
          onPress={() => {
            const MyObjectProps = Object.keys(MyObject);

            console.log(MyObjectProps);
            Alert.alert(MyObjectProps.toString());
          }}
        >
          <Text style={styles.buttonText}>Get Props of MyObject</Text>
        </Pressable>

        <View style={styles.devider} />

        <Pressable
          style={styles.button}
          onPress={() => {
            const res = MyObject.doSomeThing;

            console.log(res);
            Alert.alert(String(res));
          }}
        >
          <Text style={styles.buttonText}>Do SomeThing</Text>
        </Pressable>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  safeAreaView: { flex: 1 },
  container: {
    flex: 1,
    padding: 5,
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  result: {
    fontSize: 30,
    fontWeight: '400',
  },

  devider: {
    height: 1,
    backgroundColor: '#999',
    width: '100%',
    marginVertical: 20,
  },

  button: {
    backgroundColor: 'royalblue',
    padding: 10,
    borderRadius: 15,
    width: '65%',
  },

  buttonText: {
    fontSize: 20,
    color: '#FFF',
  },
});
