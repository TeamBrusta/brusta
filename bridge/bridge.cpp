#include "model/model.hpp"
#include "bridge.hpp"

/* JNI */

JNIEXPORT jlong JNICALL Java_EvalJNI_loadModel
  (JNIEnv * env, jobject thisObj, jstring modelName, jint inputSequenceSize, jint inputFeatureSize, jint outputSize) {
  const char* modelNameString = env -> GetStringUTFChars(modelName, 0);
  pytorch::Eval eval = pytorch::Eval();
  long pModel = eval.loadModel(modelNameString, inputSequenceSize, inputFeatureSize, outputSize);
  env -> ReleaseStringUTFChars(modelName, modelNameString);
  return pModel;
}

JNIEXPORT jfloatArray JNICALL Java_EvalJNI_evaluate
  (JNIEnv * env, jobject thisObj, jlong pModel, jfloatArray x) {
    pytorch::Model* model = (pytorch::Model*)((long)pModel);
    jfloatArray result = env -> NewFloatArray(model->getOutputSize());
    jfloat* jX = env -> GetFloatArrayElements(x, 0);

    pytorch::Eval eval = pytorch::Eval();
    float* y = eval.evaluate(pModel, jX);

    env -> ReleaseFloatArrayElements(x, jX, 0);
    env -> SetFloatArrayRegion(result, 0, model->getOutputSize(), y);
    return result;
}

/* C Interface */

pytorch::Eval* AsCppEval(Eval eval) {
    return reinterpret_cast<pytorch::Eval*>(eval);
}

Eval EvalInit() {
    return (Eval)(new pytorch::Eval());    
}

void EvalFree(Eval eval) {
    delete AsCppEval(eval);
}

long EvalLoadModel(Eval eval, const char* modelName, int inputSequenceSize, int inputFeatureSize, int outputSize) {
    return AsCppEval(eval)->loadModel(modelName, inputSequenceSize, inputFeatureSize, outputSize);
}

float* EvalEvaluate(Eval eval, long pModel, float* x) {
    return AsCppEval(eval)->evaluate(pModel, x);
}