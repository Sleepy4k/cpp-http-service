#pragma once

#ifndef DEBUG_HELPER_HPP
#define DEBUG_HELPER_HPP

#include <iostream>

namespace debug {
  static void print(const std::string &message) {
    std::cout << message << std::endl;
  }

  static void quit(const std::string &message) {
    print("ERROR: " + message);
    exit(1);
  }
}

#endif // DEBUG_HELPER_HPP