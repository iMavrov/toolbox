#pragma once

#include <ratio>

namespace toolbox {

namespace unit {

/// @brief Linear unit
/// @tparam T
/// @tparam Period
template <typename T, typename Period = std::ratio<1>>
class Unit {
 public:
  static_assert(std::is_arithmetic<T>::value, "Unit expects an arithmetic type for 'T'");

  Unit() : value(0) {}

  explicit Unit(const T &value) : value(value) {}

  T Get() const { return value; }

  template <typename NewPeriod>
  Unit<T, NewPeriod> To() const {
    return To<T, NewPeriod>();
  }

  template <typename NewType, typename NewPeriod>
  Unit<NewType, NewPeriod> To() const {
    typedef std::ratio_divide<Period, NewPeriod> Quotient;
    return Unit<NewType, NewPeriod>(static_cast<NewType>(value) *
                                    static_cast<NewType>(Quotient::num) /
                                    static_cast<NewType>(Quotient::den));
  }

  // x + y
  friend Unit operator+(const Unit &lhs, const Unit &rhs) { return Unit(lhs.value + rhs.value); }

  // x - y
  friend Unit operator-(const Unit &lhs, const Unit &rhs) { return Unit(lhs.value - rhs.value); }

  // a * x
  friend Unit operator*(const T &lhs, const Unit &rhs) { return Unit(lhs * rhs.value); }

  // x * a
  friend Unit operator*(const Unit &lhs, const T &rhs) { return Unit(lhs.value * rhs); }

  // x / a
  friend Unit operator/(const Unit &lhs, const T &rhs) { return Unit(lhs.value / rhs); }

  // x += y
  Unit &operator+=(const Unit &rhs) {
    value += rhs.value;
    return *this;
  }

  // x -= y
  Unit &operator-=(const Unit &rhs) {
    value -= rhs.value;
    return *this;
  }

  // x *= a
  Unit &operator*=(const T &rhs) {
    value *= rhs;
    return *this;
  }

  // x / a
  Unit &operator/=(const T &rhs) {
    value /= rhs;
    return *this;
  }

 protected:
  T value;
};

}  // namespace unit

}  // namespace toolbox
