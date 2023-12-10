#pragma once

#include "units/unit.hpp"

namespace toolbox {

namespace units {

template <typename T, typename Period = std::ratio<1>>
class Distance : public Unit<T, Period> {
 public:
  Distance() = default;

  explicit Distance(const T &value) : Unit(value) {}
};

}  // namespace units

}  // namespace toolbox
