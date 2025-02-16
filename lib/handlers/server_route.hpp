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
        this->setRouter(router);
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
       * @brief Set the Router object
       * 
       * @param router (Router) The router object
       * 
       * @return void
       */
      void setRouter(Router router) {
        // Merge the path with prefix
        // so if path is /about and prefix is /api
        // the path will be /api/about
        for (Route route : router.routes) {
          route.path = router.prefix + route.path;
        }


        router_list.push_back(router);
      }

      /**
       * @brief Add a new router
       * 
       * @param router (Router) The router object
       * 
       * @return void
       */
      void addRouter(Router router) {
        // Push the router object to the router list
        // if router prefix is already exist merge the routes
        // else add the router to the list
        for (Router r : router_list) {
          if (r.prefix == router.prefix) {
            for (Route route : router.routes) {
              for (Route route : router.routes) {
                route.path = router.prefix + route.path;
              }

              r.routes.push_back(route);
            }
          } else {
            router_list.push_back(router);
          }
        }
      }

      /**
       * @brief Get the Route object
       * 
       * @param route (std::string) The route name
       * 
       * @return Route
       */
      Route getRoute(std::string prefix, std::string name) {
        for (Router router : router_list) {
          if (router.prefix == prefix) {
            for (Route route : router.routes) {
              if ((route.path == "/" || route.path == "") && prefix == name) {
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

      /**
       * @brief Add a new route
       * 
       * @param route (Route) The route object
       * 
       * @return void
       */
      void addRoute(Route route, std::string prefix) {
        bool isExist = false;

        for (Router router : router_list) {
          if (router.prefix == prefix) {
            router.routes.push_back(route);
            isExist = true;
          }
        }

        if (!isExist) {
          // Create message error
          debug::quit(parse::message("ERROR: Route prefix not found for route %1", {route.name}));
          // Force exit
          exit(1);
        }
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
      std::vector<Router> router_list;
  };
}

#endif // SERVER_ROUTE_HPP