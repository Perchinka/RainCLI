cmake_minimum_required(VERSION 3.10)
project(cli_rain
  VERSION 0.1
  DESCRIPTION "Terminal rain + thunder effect"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(WARNING "In-source builds are discouraged.")
endif()

add_subdirectory(src)

add_subdirectory(tests)
