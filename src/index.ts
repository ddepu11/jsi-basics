import { NativeModules } from 'react-native';

// NativeModules.

declare global {
  function nativeCallSyncHook(): unknown;
  var jsiMultiply: Function | undefined;
}

if (global.jsiMultiply === undefined) {
  const JsiBasics = NativeModules.JsiBasics;

  if (JsiBasics === null) {
    throw new Error('Base JsiBasics module not found, Try rebuilding the app.');
  }

  if (global.nativeCallSyncHook === null || JsiBasics.install === null) {
    throw new Error('Failed to install JsiBasics!');
  }

  const isModuleInstalled = JsiBasics.install();

  if (isModuleInstalled !== true) {
    throw new Error('Could not install JsiBasics!');
  }

  if (global.jsiMultiply === null) {
    throw new Error(
      'Could not install JsiBasics! The initiallzed function does not exists!!!'
    );
  }
}

const jsiMultiply = (a: number, b: number) => {
  return global.jsiMultiply ? global.jsiMultiply(a, b) : undefined;
};

export { jsiMultiply };
