#ifdef __cplusplus
extern "C" {
#endif

/* Eval */
typedef void* Eval;

Eval EvalInit();
void EvalFree(Eval);
long EvalLoadModel(Eval eval, const char* modelName);
float* EvalEvaluate(Eval eval, long pModel, float* x);

#ifdef __cplusplus
}
#endif
