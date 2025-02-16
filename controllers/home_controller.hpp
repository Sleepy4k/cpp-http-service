#pragma once

#ifndef HOME_CONTROLLER_HPP
#define HOME_CONTROLLER_HPP

#include "../lib/helpers/view_helper.hpp"

struct HomeController {
  std::string index() {
    return view::render("./view/home.html", {
      {"title", "Home Page"},
      {"content", "Welcome to the Home Page"}
    });
  }

  std::string about() {
    return view::render("./view/about.html");
  }
};

#endif // HOME_CONTROLLER_HPP