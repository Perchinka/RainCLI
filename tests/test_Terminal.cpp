#include "../include/ITerminalIO.hpp"
#include "../include/StandartTerminal.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace cli_rain;

// A simple mock that records all writes:
struct MockIO : ITerminalIO {
  std::vector<std::string> calls;
  void write(const std::string &s) override { calls.push_back(s); }
  void flush() override { calls.push_back("<FLUSH>"); }
};

TEST(TerminalTests, ClearScreenEmitsCSI2J) {
  MockIO io;
  {
    Terminal term(io);
    term.clearScreen();
    term.flush();
  }
  ASSERT_EQ(io.calls.size(), 2);
  EXPECT_EQ(io.calls[0], "\x1b[2J");
  EXPECT_EQ(io.calls[1], "<FLUSH>");
}

TEST(TerminalTests, MoveCursorEmitsCorrectSequence) {
  MockIO io;
  Terminal term(io);
  term.moveCursor(5, 10);
  term.flush();

  ASSERT_EQ(io.calls.size(), 2) << "Expected exactly one write + one flush";
  EXPECT_EQ(io.calls[0], "\x1b[5;10H");
  EXPECT_EQ(io.calls[1], "<FLUSH>");
}

TEST(TerminalTests, ColorAndReset) {
  MockIO io;
  Terminal term(io);
  term.setForeground(Color::Green);
  term.setBackground(Color::Red);
  term.resetAttributes();
  term.flush();

  std::vector<std::string> expected = {"\x1b[32m", // Green foreground
                                       "\x1b[41m", // Red background
                                       "\x1b[0m",  // Reset
                                       "<FLUSH>"};
  EXPECT_EQ(io.calls, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
