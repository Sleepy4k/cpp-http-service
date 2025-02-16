#pragma once

#ifndef API_HPP
#define API_HPP

#include "../lib/structs/server_route_struct.hpp"
#include "../lib/structs/server_router_struct.hpp"

#include "../controllers/api_controller.hpp"

Router api() {
  Router router = Router("/api");

  router.get("/", ApiController().index(), "home");
  router.get("/about", ApiController().about(), "about");

  return router;
}

#endif // API_HPP