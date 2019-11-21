#include "model.hpp"
#include "cmodel.h"

/* Eval */

pytorch::Eval* AsCppEval(Eval eval) {
    return reinterpret_cast<pytorch::Eval*>(eval);
}

Eval EvalInit() {
    return (Eval)(new pytorch::Eval());    
}

void EvalFree(Eval eval) {
    delete AsCppEval(eval);
}

long EvalLoadModel(Eval eval, const char* modelName) {
    return AsCppEval(eval)->loadModel(modelName);
}

float* EvalEvaluate(Eval eval, long pModel, float* x) {
    return AsCppEval(eval)->evaluate(pModel, x);
}