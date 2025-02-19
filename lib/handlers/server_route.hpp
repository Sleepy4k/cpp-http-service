#pragma once

#ifndef SERVER_ROUTE_HPP
#define SERVER_ROUTE_HPP

#include <vector>

#include "../helpers/debug_helper.hpp"
#include "../helpers/parse_helper.hpp"
#include "../structs/server_route_struct.hpp"
#include "../structs/server_router_struct.hpp"

namespace http {
  class ServerRoute {
    public:
      /**
       * @brief Construct a new Server Route object
       * 
       * @return void
       */
      ServerRoute() {}

      /**
       * @brief Construct a new Server Route object
       * 
       * @param route (Router) The router object
       * 
       * @return void
       */
      ServerRoute(Router router) {
        this->addRouter(router);
      }

      /**
       * @brief Get the Router object
       * 
       * @return std::vector<Router> 
       */
      std::vector<Router> getRouter() {
        return router_list;
      }

      /**
       * @brief Add a new router
       * 
       * @param router (Router) The router object
       * 
       * @return void
       */
      void addRouter(Router router) {
        pushRouter(router);
      }

      /**
       * @brief Get the Route object
       * 
       * @param route (std::string) The route name
       * 
       * @return Route
       */
      Route getRoute(std::string prefix, std::string name) {
        return findRoute(prefix, name);
      }

      /**
       * @brief Check if the router is empty
       * 
       * @return bool
       */
      bool isEmpty() {
        return router_list.empty();
      }

    private:
      /**
       * @brief Initialize the router list
       * 
       * @var std::vector<Router> router_list
       */
      std::vector<Router> router_list;

      /**
       * @brief Parse the router
       * 
       * @param router (Router) The router object
       * 
       * @return void
       */
      void parseRouter(Router *router) {
        for (Route route : router->routes) {
          route.path = router->prefix + route.path;
        }
      }

      /**
       * @brief Push the router to the router list
       * 
       * @param router (Router) The router object
       * 
       * @return void
       */
      void pushRouter(Router router) {
        const bool isPrefixExist = router.prefix.empty();

        if (router_list.empty()) {
          if (isPrefixExist) parseRouter(&router);

          router_list.push_back(router);
          return;
        }

        for (Router list: router_list) {
          if (list.prefix == router.prefix) {
            parseRouter(&router);

            list.routes.insert(list.routes.end(), router.routes.begin(), router.routes.end());
            return;
          }

          if (isPrefixExist) parseRouter(&router);

          router_list.push_back(router);
        }
      }

      /**
       * @brief Find the route
       * 
       * @param prefix (std::string) The route prefix
       * @param name (std::string) The route name
       * 
       * @return Route
       */
      Route findRoute(std::string prefix, std::string name) {
        if (router_list.empty()) return Route();

        for (Router router: router_list) {
          if (router.prefix == prefix) {
            for (Route route : router.routes) {
              if ((route.path == "/" || route.path.empty()) && prefix == name) {
                return route;
              }

              if ((prefix + route.path) == name) {
                return route;
              }
            }
          }
        }

        return Route();
      }
  };
}

#endif // SERVER_ROUTE_HPP