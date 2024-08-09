#pragma once

#ifndef WEB_HPP
#define WEB_HPP

#include "../lib/structs/server_route_struct.hpp"
#include "../lib/structs/server_router_struct.hpp"

Router web() {
  Router router = Router("");

  router.routes.push_back(Route("home", "GET", "/", "index"));
  router.routes.push_back(Route("about", "GET", "/about", "about"));

  return router;
}

#endif // WEB_HPP