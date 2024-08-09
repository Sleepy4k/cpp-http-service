#pragma once

#ifndef SERVER_ROUTE_STRUCT_HPP
#define SERVER_ROUTE_STRUCT_HPP

#include <string>

struct Route {
  std::string name;
  std::string method;
  std::string path;
  std::string controller;

  Route() : name(""), method("GET"), path("/"), controller("index") {}
  Route(std::string name, std::string method, std::string path, std::string controller) : name(name), method(method), path(path), controller(controller) {}

  bool isEmpty() {
    return name == "" && method == "GET" && path == "/" && controller == "index";
  }
};

#endif // SERVER_ROUTE_STRUCT_HPP