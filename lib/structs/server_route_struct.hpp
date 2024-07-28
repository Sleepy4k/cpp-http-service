#pragma once

#ifndef SERVER_ROUTE_STRUCT_HPP
#define SERVER_ROUTE_STRUCT_HPP

#include <string>

#include "../enums/http_method_enum.hpp"

struct ServerRoute {
  HttpMethodEnum method;
  std::string path;
  std::string handler;

  ServerRoute() : method(HttpMethodEnum::GET), path("/"), handler("default") {}
  ServerRoute(HttpMethodEnum method, std::string path, std::string handler) : method(method), path(path), handler(handler) {}
};

#endif // SERVER_ROUTE_STRUCT_HPP