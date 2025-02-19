#pragma once

#ifndef REQUEST_HEADER_SERVICE_HPP
#define REQUEST_HEADER_SERVICE_HPP

#include <string>

struct RequestHeader {
  std::string method = "GET";
  std::string endpoint = "127.0.0.1";
  std::string content;
  std::string accept = "*/*";
  std::string content_type = "application/json";
  std::string content_length = "0";

  /**
   * @brief Check if the request header is empty
   *
   * @return boolean
   */
  bool is_empty() const
  {
    return method.empty() || endpoint.empty() || content.empty() || accept.empty() || content_type.empty() || content_length.empty();
  }

  /**
   * @brief Fill the empty request header with default values
   *
   * @return void
   */
  void fill_empty()
  {
    if (method.empty()) method = "GET";
    if (endpoint.empty()) endpoint = "127.0.0.1";
    if (accept.empty()) accept = "*/*";
    if (content_type.empty()) content_type = "application/json";
    if (content_length.empty()) content_length = "0";
  }

  /**
   * @brief Check if the request header wants json response
   *
   * @return boolean
   */
  bool want_json() const
  {
    return accept.find("/json") != std::string::npos;
  }

  /**
   * @brief Check if the request header wants xml response
   *
   * @return boolean
   */
  bool want_xml() const
  {
    return accept.find("/xml") != std::string::npos;
  }

  /**
   * @brief Check if the request header wants html response
   *
   * @return boolean
   */
  bool want_html() const
  {
    return accept.find("/html") != std::string::npos;
  }
};

#endif // REQUEST_HEADER_SERVICE_HPP
