#include "napi.h"

using namespace Napi;

Object InitArrayBuffer(Env env);
Object InitAsyncContext(Env env);
#if (NAPI_VERSION > 3)
Object InitAsyncProgressWorker(Env env);
#endif
Object InitAsyncWorker(Env env);
Object InitPersistentAsyncWorker(Env env);
Object InitBasicTypesArray(Env env);
Object InitBasicTypesBoolean(Env env);
Object InitBasicTypesNumber(Env env);
Object InitBasicTypesValue(Env env);
// Currently experimental guard with NODE_MAJOR_VERISION in which it was
// released. Once it is no longer experimental guard with the NAPI_VERSION
// in which it is released instead.
#if (NODE_MAJOR_VERSION >= 10)
Object InitBigInt(Env env);
#endif
Object InitBuffer(Env env);
#if (NAPI_VERSION > 2)
Object InitCallbackScope(Env env);
#endif
#if (NAPI_VERSION > 4)
Object InitDate(Env env);
#endif
Object InitDataView(Env env);
Object InitDataViewReadWrite(Env env);
Object InitError(Env env);
Object InitExternal(Env env);
Object InitFunction(Env env);
Object InitHandleScope(Env env);
Object InitMemoryManagement(Env env);
Object InitName(Env env);
Object InitObject(Env env);
#ifndef NODE_ADDON_API_DISABLE_DEPRECATED
Object InitObjectDeprecated(Env env);
#endif // !NODE_ADDON_API_DISABLE_DEPRECATED
Object InitPromise(Env env);
Object InitRunScript(Env env);
#if (NAPI_VERSION > 3)
Object InitThreadSafeFunctionCtx(Env env);
Object InitThreadSafeFunctionExistingTsfn(Env env);
Object InitThreadSafeFunctionPtr(Env env);
Object InitThreadSafeFunctionSum(Env env);
Object InitThreadSafeFunctionUnref(Env env);
Object InitThreadSafeFunction(Env env);
#endif
Object InitTypedArray(Env env);
Object InitObjectWrap(Env env);
Object InitObjectWrapConstructorException(Env env);
Object InitObjectWrapRemoveWrap(Env env);
Object InitObjectReference(Env env);
Object InitVersionManagement(Env env);
Object InitThunkingManual(Env env);

Object Init(Env env, Object exports) {
  exports.Set("arraybuffer", InitArrayBuffer(env));
  exports.Set("asynccontext", InitAsyncContext(env));
#if (NAPI_VERSION > 3)
  exports.Set("asyncprogressworker", InitAsyncProgressWorker(env));
#endif
  exports.Set("asyncworker", InitAsyncWorker(env));
  exports.Set("persistentasyncworker", InitPersistentAsyncWorker(env));
  exports.Set("basic_types_array", InitBasicTypesArray(env));
  exports.Set("basic_types_boolean", InitBasicTypesBoolean(env));
  exports.Set("basic_types_number", InitBasicTypesNumber(env));
  exports.Set("basic_types_value", InitBasicTypesValue(env));
// Currently experimental guard with NODE_MAJOR_VERISION in which it was
// released. Once it is no longer experimental guard with the NAPI_VERSION
// in which it is released instead.
#if (NODE_MAJOR_VERSION >= 10)
  exports.Set("bigint", InitBigInt(env));
#endif
#if (NAPI_VERSION > 4)
  exports.Set("date", InitDate(env));
#endif
  exports.Set("buffer", InitBuffer(env));
#if (NAPI_VERSION > 2)
  exports.Set("callbackscope", InitCallbackScope(env));
#endif
  exports.Set("dataview", InitDataView(env));
  exports.Set("dataview_read_write", InitDataView(env));
  exports.Set("dataview_read_write", InitDataViewReadWrite(env));
  exports.Set("error", InitError(env));
  exports.Set("external", InitExternal(env));
  exports.Set("function", InitFunction(env));
  exports.Set("name", InitName(env));
  exports.Set("handlescope", InitHandleScope(env));
  exports.Set("memory_management", InitMemoryManagement(env));
  exports.Set("object", InitObject(env));
#ifndef NODE_ADDON_API_DISABLE_DEPRECATED
  exports.Set("object_deprecated", InitObjectDeprecated(env));
#endif // !NODE_ADDON_API_DISABLE_DEPRECATED
  exports.Set("promise", InitPromise(env));
  exports.Set("run_script", InitRunScript(env));
#if (NAPI_VERSION > 3)
  exports.Set("threadsafe_function_ctx", InitThreadSafeFunctionCtx(env));
  exports.Set("threadsafe_function_existing_tsfn", InitThreadSafeFunctionExistingTsfn(env));
  exports.Set("threadsafe_function_ptr", InitThreadSafeFunctionPtr(env));
  exports.Set("threadsafe_function_sum", InitThreadSafeFunctionSum(env));
  exports.Set("threadsafe_function_unref", InitThreadSafeFunctionUnref(env));
  exports.Set("threadsafe_function", InitThreadSafeFunction(env));
#endif
  exports.Set("typedarray", InitTypedArray(env));
  exports.Set("objectwrap", InitObjectWrap(env));
  exports.Set("objectwrapConstructorException",
      InitObjectWrapConstructorException(env));
  exports.Set("objectwrap_removewrap", InitObjectWrapRemoveWrap(env));
  exports.Set("objectreference", InitObjectReference(env));
  exports.Set("version_management", InitVersionManagement(env));
  exports.Set("thunking_manual", InitThunkingManual(env));
  return exports;
}

NODE_API_MODULE(addon, Init)
