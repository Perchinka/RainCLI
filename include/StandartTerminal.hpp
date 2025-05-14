#pragma once
#include "ITerminalIO.hpp"

namespace cli_rain {

enum class Color : int {
  Default = 39,
  Black = 30,
  Red = 31,
  Green = 32,
  Yellow = 33,
  Blue = 34,
  Magenta = 35,
  Cyan = 36,
  White = 37,
};

class Terminal {
public:
  explicit Terminal(ITerminalIO &io);
  ~Terminal();

  void clearScreen();
  void clearLine();
  void moveCursor(int row, int col);
  void hideCursor();
  void showCursor();
  void setForeground(Color c);
  void setBackground(Color c);
  void resetAttributes();
  void flush();

private:
  ITerminalIO &io_;
  void enableRawMode();
  void disableRawMode();
};

} // namespace cli_rain
