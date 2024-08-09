#pragma once

#ifndef PARSE_HELPER_HPP
#define PARSE_HELPER_HPP

#include <string>
#include <vector>

namespace parse {
  /**
   * @brief Parse a message with arguments,
   *        example: (%1 %2", ["hello", "world"])
   *        would return "hello world"
   * 
   * @param message (std::string) - The message to parse
   * @param args (std::vector<std::string>) - The arguments to parse
   * 
   * @return std::string
   */
  static std::string message(const std::string &message, const std::vector<std::string> &args) {
    std::string parsed_message = message;

    for (int i = 0; i < args.size(); i++) {
      std::string arg = args[i];
      std::string placeholder = "%" + std::to_string(i + 1);

      size_t pos = parsed_message.find(placeholder);

      if (pos != std::string::npos) {
        parsed_message.replace(pos, placeholder.length(), arg);
      }
    }

    return parsed_message;
  }

  /**
   * @brief Parse data from uppercase to lowercase
   * 
   * @param data (std::string) - The data to parse
   * 
   * @return std::string
   */
  static std::string to_lower(const std::string &data) {
    std::string parsed_data = data;

    for (int i = 0; i < parsed_data.length(); i++) {
      parsed_data[i] = tolower(parsed_data[i]);
    }

    return parsed_data;
  }
}

#endif // PARSE_HELPER_HPP