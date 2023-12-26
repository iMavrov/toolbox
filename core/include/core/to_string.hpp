#pragma once

#include <sstream>
#include <string>

namespace toolbox {

namespace utils {

template <typename T>
std::string ToString() {
  return {};
}

template <typename T>
std::string ToString(const T &t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

}  // namespace utils

}  // namespace toolbox
