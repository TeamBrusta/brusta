#include <iostream>
#include <torch/script.h>
#include <model.hpp>

#define BATCH_SIZE 1

using namespace std;

namespace pytorch {
	Model::Model (string modelName, int inputSequenceSize, int inputFeatureSize, int outputSize)
		: modelName(modelName), inputSequenceSize(inputSequenceSize), inputFeatureSize(inputFeatureSize), outputSize(outputSize) {
			this->module = torch::jit::load(modelName);
		}

	Model::~Model () {}

	vector<float> Model::predict (vector<float> x) {
		at::Tensor inputVector = torch::from_blob(&x[0], {BATCH_SIZE, inputSequenceSize, inputFeatureSize}, at::kFloat).clone();

		vector<torch::jit::IValue> inputTensor;
		inputTensor.push_back(inputVector);

		at::Tensor outputTensor = this->module.forward(inputTensor).toTensor();

		vector<float> outputVector(outputTensor.data_ptr<float>(), outputTensor.data_ptr<float>() + outputTensor.numel());
		return outputVector;
	}

	int Model::getInputSequenceSize() {
		return this->inputSequenceSize;
	}

	int Model::getInputFeatureSize() {
		return this->inputFeatureSize;
	}

	int Model::getOutputSize() {
		return this->outputSize;
	}

	Eval::Eval () {}

	Eval::~Eval () {}

	long Eval::loadModel (const char* modelName, int inputSequenceSize, int inputFeatureSize, int outputSize) {
		Model* pModel = new Model(modelName, inputSequenceSize, inputFeatureSize, outputSize);
		return long (pModel);
	}

	float* Eval::evaluate(long pModel, float* x) {
		int inputSequenceSize = ((Model*)pModel)->getInputSequenceSize();
		int inputFeatureSize = ((Model*)pModel)->getInputFeatureSize();
		int outputSize = ((Model*)pModel)->getOutputSize();

		vector<float> vectorX (x, x + BATCH_SIZE * inputSequenceSize * inputFeatureSize);
		vector<float> vectorY = ((Model*)pModel)->predict(vectorX);

		float *y = new float[outputSize];
		for (int i = 0; i < BATCH_SIZE * outputSize; ++i) {
			y[i] = vectorY[i];
		}
		return y;
	}
}
