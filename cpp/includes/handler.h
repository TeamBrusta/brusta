//
// Created by 조승혁 on 2019/11/21.
//

#ifndef BRUSTACPLUSPLUS_HANDLER_H
#define BRUSTACPLUSPLUS_HANDLER_H

#include <httplib.h>

void AliveCheckHandler(const httplib::Request& req, httplib::Response& res);
void PredictHandler(const httplib::Request& req, httplib::Response& res);

#endif //BRUSTACPLUSPLUS_HANDLER_H
