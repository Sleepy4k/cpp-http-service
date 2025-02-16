#pragma once

#ifndef WEB_HPP
#define WEB_HPP

#include "../lib/structs/server_route_struct.hpp"
#include "../lib/structs/server_router_struct.hpp"

#include "../controllers/home_controller.hpp"

Router web() {
  Router router = Router();

  router.get("/", HomeController().index(), "home");
  router.get("/about", HomeController().about());

  return router;
}

#endif // WEB_HPP