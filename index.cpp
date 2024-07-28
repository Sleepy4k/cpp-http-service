#include "lib/handlers/http_server.hpp"
#include "lib/structs/server_config_struct.hpp"

int main() {
  using namespace http;

  ServerConfig config("127.0.0.1", 8080);
  TCPServer server = TCPServer(config);
  server.run();
}