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
};

#endif // SERVER_ROUTER_STRUCT_HPP