#pragma once

#ifndef API_CONTROLLER_HPP
#define API_CONTROLLER_HPP

#include "../lib/helpers/response_helper.hpp"

struct ApiController {
  std::string index() {
    return response::json("{\"message\": \"Hello, World!\"}");
  }

  std::string about() {
    return response::json("{\"message\": \"About page\"}");
  }
};

#endif // API_CONTROLLER_HPP