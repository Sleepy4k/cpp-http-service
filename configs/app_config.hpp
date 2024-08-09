#pragma once

#include "../lib/enums/app_env_enum.hpp"

#ifndef APP_NAME_CONFIG
  #define APP_NAME_CONFIG "CPP HTTP Server"
#endif // APP_NAME_CONFIG

#ifndef APP_VERSION_CONFIG
  #define APP_VERSION_CONFIG "1.0.0"
#endif // APP_VERSION_CONFIG

#ifndef APP_PORT_CONFIG
  #define APP_PORT_CONFIG 8000
#endif // APP_PORT_CONFIG

#ifndef APP_HOST_CONFIG
  #define APP_HOST_CONFIG "127.0.0.1"
#endif // APP_HOST_CONFIG

#ifndef APP_ENVIRONMENT_CONFIG
  #define APP_ENVIRONMENT_CONFIG AppEnvironment::DEVELOPMENT
#endif // APP_ENVIRONMENT_CONFIG
