#include "handler.h"

int main(int argc, char **argv) {
    using namespace httplib;

    Server server;
    server.Get("/", AliveCheckHandler);
    server.Post("/predict", PredictHandler);

    server.listen("localhost", 8080);

    return 0;
}