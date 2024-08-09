#pragma once

#ifndef API_HPP
#define API_HPP

#include "../lib/structs/server_route_struct.hpp"
#include "../lib/structs/server_router_struct.hpp"

Router api() {
  Router router = Router("/api");

  router.routes.push_back(Route("home", "GET", "/", "index"));
  router.routes.push_back(Route("about", "GET", "/about", "about"));

  return router;
}

#endif // API_HPP