#pragma once

#ifndef RESPONSE_HELPER_HPP
#define RESPONSE_HELPER_HPP

#include <string>

namespace response {
  const std::string json(const std::string &json) {
    return "HTTP/1.1 200 OK\nContent-Type: application/json\nContent-Length: " + std::to_string(json.size()) + "\n\n" + json;
  }

  const std::string html(const std::string &html) {
    return "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + std::to_string(html.size()) + "\n\n" + html;
  }
}

#endif // RESPONSE_HELPER_HPP