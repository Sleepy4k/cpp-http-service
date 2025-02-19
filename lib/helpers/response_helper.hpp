#pragma once

#ifndef RESPONSE_HELPER_HPP
#define RESPONSE_HELPER_HPP

#include <string>

namespace response {
  const std::string json(const std::string &json) {
    std::string json_obj = json;

    for (int i = 0; i < json_obj.size(); i++) {
      if (json_obj[i] == '\'') {
        json_obj[i] = '\"';
      }
    }

    return "HTTP/1.1 200 OK\nContent-Type: application/json\nContent-Length: " + std::to_string(json_obj.size()) + "\n\n" + json_obj;
  }

  const std::string html(const std::string &html) {
    return "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + std::to_string(html.size()) + "\n\n" + html;
  }
}

#endif // RESPONSE_HELPER_HPP