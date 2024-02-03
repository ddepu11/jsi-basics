import { NativeModules } from 'react-native';

declare global {
  function nativeCallSyncHook(): unknown;
  var __JsiBasics: Object | undefined;
}

if (global.__JsiBasics === undefined) {
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

  if (global.__JsiBasics === null) {
    throw new Error(
      'Could not install JsiBasics! The initiallzed function does not exists!!!'
    );
  }
}

const proxy = global.__JsiBasics;

export const JSIBasics = proxy as {
  jsiMultiply: (a: number, b: number) => number;
};
