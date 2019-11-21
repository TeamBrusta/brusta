#ifndef __BRIDGE_HPP__
#define __BRIDGE_HPP__

#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

/* JNI */

JNIEXPORT jlong JNICALL Java_EvalJNI_loadModel
  (JNIEnv *, jobject, jstring);

JNIEXPORT jfloatArray JNICALL Java_EvalJNI_evaluate
  (JNIEnv *, jobject, jlong, jfloatArray);

/* C Interface */

typedef void* Eval;

Eval EvalInit();
void EvalFree(Eval);
long EvalLoadModel(Eval eval, const char* modelName);
float* EvalEvaluate(Eval eval, long pModel, float* x);

#ifdef __cplusplus
}
#endif

#endif