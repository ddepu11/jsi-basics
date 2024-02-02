import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import { jsiMultiply } from 'react-native-jsi-basics';

const result = jsiMultiply(12, 4);

export default function App() {
  return (
    <View style={styles.container}>
      <Text style={styles.result}>Result: {result}</Text>
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
