//
// Created by 조승혁 on 2019/11/21.
//

#include <json/json.h>
#include <iostream>
#include "predict.h"

static bool ParseInput(const std::string& body, Json::Value& input) {
    try {
        std::stringstream stream;

        stream.str(body);
        stream >> input;

        return !input["input"].isNull() && input["input"].isArray();
    } catch(const Json::RuntimeError& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}

bool ValidateInput(const std::string& body, std::vector<std::vector<int> >& inputs) {
    int rows = 3, cols = 5;
    Json::Value parsedObj;

    if(!ParseInput(body, parsedObj)) return false;

    if(parsedObj["input"].size() != rows) return false;
    inputs = std::vector<std::vector<int> >();

    for(const auto& input: parsedObj["input"]) {
        if(input.size() != cols || !input.isArray()) return false;
        std::vector<int> result = std::vector<int>();
        for(const auto& element: input) {
            result.push_back(element.asInt());
        }

        inputs.push_back(result);
    }

    return true;
}

void RunModel(const std::vector<std::vector<int> >& input, std::vector<int>& output) {
    output = std::vector<int>(3, 0);

    for(int i = 0; i < 3; i++) {
        for(const auto& element: input[i]) output[i] += element;
    }
}