#include <httplib.h>

int main() {
    using namespace httplib;

    Server server;
    server.Get("/", [](const Request& req, Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    server.listen("localhost", 8080);

    return 0;
}