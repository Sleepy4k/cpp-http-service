// Custom includes for the project for
// importing the necessary libraries and headers
#include "configs/app_config.hpp"

// Default includes for the project
#include "lib/configs/app_config.hpp"
#include "lib/handlers/server_http.hpp"
#include "lib/structs/server_config_struct.hpp"

// Custom includes for the project
#include "routes/api.hpp"
#include "routes/web.hpp"

int main() {
  using namespace http;

  // Define the server configuration
  ServerConfig config(APP_HOST_CONFIG, APP_PORT_CONFIG);

  // Create the server instance
  TCPServer server = TCPServer(config);
  
  // Register the routes
  server.setRoute(api());
  server.setRoute(web());

  // Run the server
  server.run();
}
