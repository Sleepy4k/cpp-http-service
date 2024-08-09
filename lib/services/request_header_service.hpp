#pragma once

#ifndef REQUEST_HEADER_SERVICE_HPP
#define REQUEST_HEADER_SERVICE_HPP

#include <string>

struct RequestHeader {
  std::string method;
  std::string endpoint;
  std::string content;
  std::string accept;
  std::string content_type;
  std::string content_length;

  // Make constructor
  RequestHeader() {
    method = "GET";
    endpoint = "127.0.0.1";
    content = "";
    accept = "*/*";
    content_type = "application/json";
    content_length = "0";
  }

  // Make deconstructor
  ~RequestHeader() {
    method = "";
    endpoint = "";
    content = "";
    accept = "";
    content_type = "";
    content_length = "";
  }

  // Cek if some of the headers are empty
  bool is_empty() {
    return method.empty() || endpoint.empty() || content.empty() || accept.empty() || content_type.empty() || content_length.empty();
  }

  // Fill the empty headers
  void fill_empty() {
    if (method.empty()) method = "GET";
    if (endpoint.empty()) endpoint = "127.0.0.1";
    if (accept.empty()) accept = "*/*";
    if (content_type.empty()) content_type = "application/json";
    if (content_length.empty()) content_length = "0";
  }

  // Check if request want json
  bool want_json() {
    // Parse the accept header to check if contains */json
    return accept.find("/json") != std::string::npos;
  }
};

#endif // REQUEST_HEADER_SERVICE_HPP