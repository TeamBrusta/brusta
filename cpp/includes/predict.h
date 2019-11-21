//
// Created by 조승혁 on 2019/11/21.
//

#ifndef BRUSTACPLUSPLUS_PREDICT_H
#define BRUSTACPLUSPLUS_PREDICT_H

#include <string>
#include <vector>

bool ValidateInput(const std::string& body, std::vector<std::vector<int> >& inputs);
void RunModel(const std::vector<std::vector<int> >& input, std::vector<int>& output);

#endif //BRUSTACPLUSPLUS_PREDICT_H
