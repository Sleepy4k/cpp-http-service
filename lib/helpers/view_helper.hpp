#pragma once

#ifndef VIEW_HELPER_HPP
#define VIEW_HELPER_HPP

#include <string>
#include <fstream>
#include <vector>

#include "./response_helper.hpp"

namespace view {
  /**
   * @brief Render the view
   * 
   * @param path (std::string) - The path to the view
   * 
   * @return std::string
   */
  const std::string render(const std::string &path) {
    std::ifstream file(path);

    if (!file.good()) {
      return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return response::html(content);
  }

  /**
   * @brief Render the view with data
   * 
   * @param path (std::string) - The path to the view
   * @param data (std::vector<std::pair<std::string, std::string>>) - The data to render
   * 
   * @return std::string
   */
  const std::string render(const std::string &path, const std::vector<std::pair<std::string, std::string>> &data) {
    std::ifstream file(path);

    if (!file.good()) {
      return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    for (const auto &d : data)
    {
      std::string key = "{{ " + d.first + " }}";
      size_t pos = content.find(key);

      while (pos != std::string::npos) {
        content.replace(pos, key.size(), d.second);
        pos = content.find(key, pos + d.second.size());
      }
    }

    return response::html(content);
  }
}

#endif // VIEW_HELPER_HPP