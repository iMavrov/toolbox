#pragma once

#include <math.h>
#include <ratio>

#include <type_traits>

namespace toolbox {

namespace units {

enum DecimalPower {
  ATTO     = -18,
  FEMTO    = -15,
  PICO     = -12,
  NANO     = -9,
  MICRO    = -6,
  MILLI    = -3,
  CENTI    = -2,
  DECI     = -1,
  UNIT     = 0,
  DECA     = 1,
  HECTO    = 2,
  KILO     = 3,
  MEGA     = 6,
  GIGA     = 9,
  TERA     = 12,
  PETA     = 15,
  EXA      = 18
};

template <typename T, int UnitPower = 1, int MultiplierPower = DecimalPower::UNIT>
class Distance {
public:
  static_assert(std::is_arithmetic<T>::value, "Distance expects an arithmetic type for 'T'");

  Distance() : value(0) {}

  explicit Distance(const T &value) : value(value) {}

  const T &Get() const { return value; }

  template<int NewMultiplierPower>
  Distance<T, UnitPower, NewMultiplierPower> To() const {
    return Distance<T, UnitPower, NewMultiplierPower>(static_cast<T>(value * pow(10.0, MultiplierPower - NewMultiplierPower)));
  }

  template<int OtherMultiplierPower>
  Distance<T, UnitPower, MultiplierPower> operator+(const Distance<T, UnitPower, OtherMultiplierPower> &rhs) const {
    return Distance<T, UnitPower, MultiplierPower>(value + rhs.To<MultiplierPower>().Get());
  }

  template<int OtherMultiplierPower>
  Distance<T, UnitPower, MultiplierPower> operator-(const Distance<T, UnitPower, OtherMultiplierPower> &rhs) const {
    return Distance<T, UnitPower, MultiplierPower>(value - rhs.To<MultiplierPower>().Get());
  }

  template<int OtherUnitPower, int OtherMultiplierPower>
  Distance<T, UnitPower + OtherUnitPower, MultiplierPower> operator*(const Distance<T, OtherUnitPower, OtherMultiplierPower> &rhs) const {
    return Distance<T, UnitPower + OtherUnitPower, MultiplierPower>(value * rhs.To<MultiplierPower>().Get());
  }

  template<int OtherUnitPower, int OtherMultiplierPower>
  Distance<T, UnitPower - OtherUnitPower, MultiplierPower> operator/(const Distance<T, OtherUnitPower, OtherMultiplierPower> &rhs) const {
    return Distance<T, UnitPower - OtherUnitPower, MultiplierPower>(value / rhs.To<MultiplierPower>().Get());
  }

private:
  static constexpr int UNIT_POWER = UnitPower;
  static constexpr int MULTIPLIER_POWER = MultiplierPower;
  T value;
};

} // units

} // toolbox
