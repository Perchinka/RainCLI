add_library(cli_rain_lib
  Terminal.cpp
)

target_include_directories(cli_rain_lib PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(cli-rain
  main.cpp
)

target_link_libraries(cli-rain PRIVATE
  cli_rain_lib
)

target_include_directories(cli-rain PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}
)
