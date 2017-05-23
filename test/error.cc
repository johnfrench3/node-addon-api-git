#include "napi.h"

using namespace Napi;

namespace {

void ThrowError(const CallbackInfo& info) {
  std::string message = info[0].As<String>().Utf8Value();
  throw Error::New(info.Env(), message);
}

void ThrowTypeError(const CallbackInfo& info) {
  std::string message = info[0].As<String>().Utf8Value();
  throw TypeError::New(info.Env(), message);
}

void ThrowRangeError(const CallbackInfo& info) {
  std::string message = info[0].As<String>().Utf8Value();
  throw RangeError::New(info.Env(), message);
}

Value CatchError(const CallbackInfo& info) {
  Function thrower = info[0].As<Function>();
  try {
    thrower({});
  } catch (const Error& e) {
     return e.Value();
  }
  return info.Env().Null();
}

Value CatchErrorMessage(const CallbackInfo& info) {
  Function thrower = info[0].As<Function>();
  try {
    thrower({});
  } catch (const Error& e) {
     std::string message = e.Message();
     return String::New(info.Env(), message);
  }
  return info.Env().Null();
}

void DoNotCatch(const CallbackInfo& info) {
  Function thrower = info[0].As<Function>();
  thrower({});
}

void CatchAndRethrowError(const CallbackInfo& info) {
  Function thrower = info[0].As<Function>();
  try {
    thrower({});
  } catch (Error& e) {
     e.Set("caught", Boolean::New(info.Env(), true));
     throw;
  }
}

void ThrowErrorThatEscapesScope(const CallbackInfo& info) {
  HandleScope scope(info.Env());

  std::string message = info[0].As<String>().Utf8Value();
  throw Error::New(info.Env(), message);
}

void CatchAndRethrowErrorThatEscapesScope(const CallbackInfo& info) {
  HandleScope scope(info.Env());
  try {
    ThrowErrorThatEscapesScope(info);
  } catch (Error& e) {
    e.Set("caught", Boolean::New(info.Env(), true));
    throw;
  }
}

} // end anonymous namespace

Object InitError(Env env) {
  Object exports = Object::New(env);
  exports["throwError"] = Function::New(env, ThrowError);
  exports["throwTypeError"] = Function::New(env, ThrowTypeError);
  exports["throwRangeError"] = Function::New(env, ThrowRangeError);
  exports["catchError"] = Function::New(env, CatchError);
  exports["catchErrorMessage"] = Function::New(env, CatchErrorMessage);
  exports["doNotCatch"] = Function::New(env, DoNotCatch);
  exports["catchAndRethrowError"] = Function::New(env, CatchAndRethrowError);
  exports["throwErrorThatEscapesScope"] = Function::New(env, ThrowErrorThatEscapesScope);
  exports["catchAndRethrowErrorThatEscapesScope"] =
    Function::New(env, CatchAndRethrowErrorThatEscapesScope);
  return exports;
}
