//
// Created by 조승혁 on 2019/11/21.
//

#include "predict.h"
#include "handler.h"

static std::string VectorJsonify(const std::string& name, const std::vector<int>& input) {
    std::string ret = "\"" + name + "\": [";

    int sz = input.size();
    for(int i = 0; i < sz; i++) {
        ret += std::to_string(input[i]) + (i < sz - 1 ? "," : "]");
    }

    return ret;
}

void AliveCheckHandler(const httplib::Request& req, httplib::Response& res) {
    res.set_content(R"({"status": "server is now running"})", "application/json");
}

void PredictHandler(const httplib::Request& req, httplib::Response& res) {
    std::vector<std::vector<int> > inputs;
    std::vector<int> output;

    if(!ValidateInput(req.body, inputs)) {
        res.set_content(R"({"message": "wrong input format"})", "application/json");
        res.status = 400;
    } else {
        RunModel(inputs, output);
        res.set_content("{" + VectorJsonify("output", output) + "}", "application/json");
    }
}