#pragma once

#ifndef SERVER_CONFIG_STRUCT_HPP
#define SERVER_CONFIG_STRUCT_HPP

#include <string>

struct ServerConfig {
  std::string hostname;
  int port;

  ServerConfig() : hostname("localhost"), port(8080) {}
  ServerConfig(std::string hostname, int port) : hostname(hostname), port(port) {}
};

#endif // SERVER_CONFIG_STRUCT_HPP