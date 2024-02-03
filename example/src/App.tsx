import * as React from 'react';

import { StyleSheet, View, Text, SafeAreaView } from 'react-native';
import { JSIBasics } from 'react-native-jsi-basics';

const result = JSIBasics.jsiMultiply(40, 5);

export default function App() {
  const { experimentWithFuntion } = JSIBasics;

  // const funcExpResult = experimentWithFuntion('Facebook');
  const funcExpResult = experimentWithFuntion('Facebook');

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
