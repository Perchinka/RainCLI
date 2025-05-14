add_executable(cli-rain
  main.cpp
)

target_include_directories(cli-rain PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}
)

