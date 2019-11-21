#include <iostream>
#include "model_rnn.hpp"
#include "model.hpp"

#define BATCH_SIZE 1

using namespace std;

namespace pytorch {
    Model::Model () {}

    Model::Model (const char* modelName) {
        this->module = torch::jit::load(modelName);
    }

    Model::~Model () {}

    vector<float> Model::predict (vector<float> x) {
        at::Tensor inputVector = torch::from_blob(&x[0], {BATCH_SIZE, INPUT_SEQUENCE_SIZE, INPUT_FEATURE_SIZE}, at::kFloat).clone();
        vector<torch::jit::IValue> inputTensor;
        inputTensor.push_back(inputVector);

        at::Tensor outputTensor = this->module.forward(inputTensor).toTensor();
        int size = outputTensor.numel();
        vector<float> outputVector(outputTensor.data_ptr<float>(), outputTensor.data_ptr<float>() + size);

        return outputVector;
    }

    Eval::Eval () {}
    Eval::~Eval () {}

    long Eval::loadModel (const char* modelName) {
        Model* pModel = new Model(modelName);
        return long (pModel);
    }
    
    float* Eval::evaluate(long pModel, float* x) {
        vector<float> vectorX (x, x + BATCH_SIZE * INPUT_SEQUENCE_SIZE * INPUT_FEATURE_SIZE);
        vector<float> vectorY = ((Model*)pModel) -> Model::predict(vectorX);
    	static float y[OUTPUT_SIZE];
        for (int i = 0; i < BATCH_SIZE * OUTPUT_SIZE; ++i) {
            y[i] = vectorY[i];
        }
        return y;
    }
}