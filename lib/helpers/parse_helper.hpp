#pragma once

#ifndef PARSE_HELPER_HPP
#define PARSE_HELPER_HPP

#include <string>
#include <vector>

namespace parse {
  /**
   * @brief Parse a message with arguments,
   *        example: ("hello %s", ["world"])
   *        would return "hello world"
   * 
   * @param message (std::string) - The message to parse
   * @param args (std::vector<std::string>) - The arguments to parse
   * 
   * @return std::string
   */
  static std::string parseMessage(const std::string &message, const std::vector<std::string> &args) {
    std::string parsed_message = message;

    for (int i = 0; i < args.size(); i++) {
      std::string arg = args[i];
      std::string placeholder = "%" + std::to_string(i + 1) + "s";

      size_t pos = parsed_message.find(placeholder);

      if (pos != std::string::npos) {
        parsed_message.replace(pos, placeholder.length(), arg);
      }
    }

    return parsed_message;
  }
}

#endif // PARSE_HELPER_HPP