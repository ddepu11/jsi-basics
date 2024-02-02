const JsiBasics = require('./NativeJsiBasics').default;

export function multiply(a: number, b: number): number {
  return JsiBasics.multiply(a, b);
}
