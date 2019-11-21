#ifndef __MODEL_H__
#define __MODEL_H__
#include <torch/script.h>

using namespace std;

namespace pytorch {
    class Model {
        public:
            Model();
            Model(const char* modelName);
            ~Model();
            torch::jit::script::Module module;
            vector<float> predict(vector<float> x);
    };

    class Eval {
        public:
            Eval();
            ~Eval();
            long loadModel(const char* modelName);
            float* evaluate(long pModel, float* x);
    };
}

#endif