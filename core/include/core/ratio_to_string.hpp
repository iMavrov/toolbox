#pragma once

#include <ratio>

#include "core/to_string.hpp"

namespace toolbox {

namespace utils {

template <>
std::string ToString<std::atto>() {
  return "a";
}

template <>
std::string ToString<std::femto>() {
  return "f";
}

template <>
std::string ToString<std::pico>() {
  return "p";
}

template <>
std::string ToString<std::nano>() {
  return "n";
}

template <>
std::string ToString<std::micro>() {
  return "u";
}

template <>
std::string ToString<std::milli>() {
  return "m";
}

template <>
std::string ToString<std::centi>() {
  return "c";
}

template <>
std::string ToString<std::deci>() {
  return "d";
}

template <>
std::string ToString<std::deca>() {
  return "da";
}

template <>
std::string ToString<std::hecto>() {
  return "h";
}

template <>
std::string ToString<std::kilo>() {
  return "k";
}

template <>
std::string ToString<std::mega>() {
  return "M";
}

template <>
std::string ToString<std::giga>() {
  return "G";
}

template <>
std::string ToString<std::tera>() {
  return "T";
}

template <>
std::string ToString<std::peta>() {
  return "P";
}

template <>
std::string ToString<std::exa>() {
  return "E";
}

}  // namespace utils

}  // namespace toolbox
