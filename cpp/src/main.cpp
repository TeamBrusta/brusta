#include <httplib.h>
#include <json/json.h>
#include <vector>

using namespace httplib;

void sample(const Request& req, Response& res) {
    Json::Value root;
    std::stringstream stream;
    std::vector<std::vector<int> > v;

    stream.str(req.body);
    stream >> root;

    for(const Json::Value& input : root["input"]) {
        std::vector<int> result;

        for (const Json::Value &element: input) {
            result.push_back(element.asInt());
        }

        v.push_back(result);
    }

    res.set_content(req.body, "application/json");
}

int main() {
    Server server;
    server.Post("/", sample);

    server.listen("localhost", 8080);

    return 0;
}