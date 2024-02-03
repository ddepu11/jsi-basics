import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import { JSIBasics } from 'react-native-jsi-basics';

const result = JSIBasics.jsiMultiply(40, 5);

export default function App() {
  const { experimentWithFuntion } = JSIBasics;

  return (
    <View style={styles.container}>
      <Text style={styles.result}>
        Result: {result} {experimentWithFuntion(2)}
      </Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  result: {
    fontSize: 35,
    fontWeight: '500',
  },
});
