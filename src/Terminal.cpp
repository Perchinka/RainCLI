#include "../include/StandartTerminal.hpp"

namespace cli_rain {

Terminal::Terminal(ITerminalIO &io) : io_(io) {}

Terminal::~Terminal() = default;

void Terminal::clearScreen() { io_.write("\x1b[2J"); }

void Terminal::clearLine() { io_.write("\x1b[K"); }

void Terminal::moveCursor(int row, int col) {
  io_.write("\x1b[" + std::to_string(row) + ";" + std::to_string(col) + "H");
}

void Terminal::hideCursor() { io_.write("\x1b[?25l"); }

void Terminal::showCursor() { io_.write("\x1b[?25h"); }

void Terminal::setForeground(Color c) {
  io_.write("\x1b[" + std::to_string(static_cast<int>(c)) + "m");
}

void Terminal::setBackground(Color c) {
  int bg = static_cast<int>(c) + 10;
  io_.write("\x1b[" + std::to_string(bg) + "m");
}

void Terminal::resetAttributes() { io_.write("\x1b[0m"); }

void Terminal::flush() { io_.flush(); }

} // namespace cli_rain
