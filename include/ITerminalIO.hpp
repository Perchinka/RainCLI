#pragma once
#include <string>

namespace cli_rain {

struct ITerminalIO {
  virtual ~ITerminalIO() = default;
  virtual void write(const std::string &s) = 0;
  virtual void flush() = 0;
};

} // namespace cli_rain
