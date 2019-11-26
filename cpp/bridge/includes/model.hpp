#ifndef __MODEL_H__
#define __MODEL_H__
#include <torch/script.h>
#include <string>

using namespace std;

namespace pytorch {
    class Model {
        public:
            Model(string modelName, int inputSequenceSize, int inputFeatureSize, int outputSize);
            ~Model();

            int getInputSequenceSize();
            int getInputFeatureSize();
            int getOutputSize();
            
            vector<float> predict(vector<float> x);
        
        private:
            torch::jit::script::Module module;

            string modelName;
            int inputSequenceSize;
            int inputFeatureSize;
            int outputSize;
    };

    class Eval {
        public:
            Eval();
            ~Eval();
            long loadModel(const char* modelName, int inputSequenceSize, int inputFeatureSize, int outputSize);
            float* evaluate(long pModel, float* x);
    };
}
#endif
