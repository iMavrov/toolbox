#pragma once

#include <ratio>

#include <type_traits>

namespace toolbox {

namespace units {

enum Derived {
  ATTO     = -18,
  FEMTO    = -15,
  PICO     = -12,
  NANO     = -9,
  MICRO    = -6,
  MILLI    = -3,
  CENTI    = -2,
  DECI     = -1,
  STANDARD = 0,
  DECA     = 1,
  HECTO    = 2,
  KILO     = 3,
  MEGA     = 6,
  GIGA     = 9,
  TERA     = 12,
  PETA     = 15,
  EXA      = 18
};

template <typename T, Derived DecimalPower = STANDARD>
class Distance {
public:
  static_assert(std::is_arithmetic<T>::value, "Distance expects an arithmetic type for 'T'");
  Distance() : value(0) {}

  explicit Distance(const T &value) : value(value) {}

  const T &Get() const { return value; }

  template<int NewDecimalPower>
  Distance<T, NewDecimalPower> To() const {
    int 
    return Distance<T, NewDecimalPower>(static_cast<T>(value * MULTIPLIERS[NewDecimalPower - DecimalPower]));
  }

  Distance operator+(const Distance &rhs) const {

  }

  Distance operator-(const Distance &rhs) const {
    
  }

private:
  static constexpr Derived DECIMAL_POWER = DecimalPower;
  T value;
};

} // units

} // toolbox
