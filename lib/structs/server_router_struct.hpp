#pragma once

#ifndef SERVER_ROUTER_STRUCT_HPP
#define SERVER_ROUTER_STRUCT_HPP

#include <string>
#include <vector>

#include "server_route_struct.hpp"

struct Router {
  std::string prefix;
  std::vector<Route> routes;

  Router() : prefix("") {}
  Router(std::string prefix) : prefix(prefix) {}

  void get(std::string path, std::string controller, std::string name = "") {
    routes.push_back(Route(name, "GET", path, controller));
  }

  void post(std::string path, std::string controller, std::string name = "") {
    routes.push_back(Route(name, "POST", path, controller));
  }

  void put(std::string path, std::string controller, std::string name = "") {
    routes.push_back(Route(name, "PUT", path, controller));
  }

  void patch(std::string path, std::string controller, std::string name = "") {
    routes.push_back(Route(name, "PATCH", path, controller));
  }

  void del(std::string path, std::string controller, std::string name = "") {
    routes.push_back(Route(name, "DELETE", path, controller));
  }
};

#endif // SERVER_ROUTER_STRUCT_HPP