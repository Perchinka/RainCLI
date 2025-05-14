find_package(GTest REQUIRED)

add_executable(test_Terminal
  test_Terminal.cpp
)

target_include_directories(test_Terminal PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test_Terminal PRIVATE
  GTest::gtest_main
  cli_rain_lib
)

set_target_properties(test_Terminal PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

add_test(
  NAME TerminalTests
  COMMAND ${CMAKE_BINARY_DIR}/tests/test_Terminal
)
