import * as React from 'react';

import { StyleSheet, View, Text, SafeAreaView } from 'react-native';
import { JSIBasics } from 'react-native-jsi-basics';

const result = JSIBasics.jsiMultiply(40, 5);

export default function App() {
  const { experimentWithFuntion } = JSIBasics;

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

  // Null, gives tyoeof as Object
  // const funcExpResult =
  //   experimentWithFuntion('') === null ? 'null' : 'not-null';

  // Undefined, gives tyoeof as undefined
  const funcExpResult =
    experimentWithFuntion('') === undefined ? 'undefined' : 'not-undefined';

  console.log('funcExpResult: ', funcExpResult);

  return (
    <SafeAreaView style={styles.safeAreaView}>
      <View style={styles.container}>
        <Text style={styles.result}>Multiplication Res: {result}</Text>

        <View style={styles.devider} />

        <Text style={styles.result}>Func Experiments: {funcExpResult}</Text>
        <Text style={styles.result}>Type: {typeof funcExpResult}</Text>
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
});
