#pragma once

#include <ratio>
#include <string>

#include "core/ratio_to_string.hpp"

#include "unit/quantity.hpp"

namespace toolbox {

namespace unit {

/// @brief Linear unit of measurement.
/// @tparam Q Unit's quantity. See 'Quantity'.
/// @tparam T Type of stored value. Must be arithmetic.
/// @tparam S Value multiplier of the unit.
template <unsigned int Q, typename T = float, typename S = std::ratio<1>>
class Unit {
 public:
  static_assert(std::is_arithmetic<T>::value, "Unit expects an arithmetic type for T");

  static constexpr unsigned int QuantityTag = Q;
  typedef T Type;
  typedef S Scale;

  /// @brief
  Unit() : value(0) {}

  /// @brief
  /// @param value
  explicit Unit(const Type &value) : value(value) {}

  /// @brief
  /// @return
  Type Get() const { return value; }

  /// @brief
  /// @tparam NewScale
  /// @return
  template <typename NewScale>
  Unit<QuantityTag, Type, NewScale> To() const {
    return To<Type, NewScale>();
  }

  /// @brief
  /// @tparam NewType
  /// @tparam NewScale
  /// @return
  template <typename NewType, typename NewScale>
  Unit<QuantityTag, NewType, NewScale> To() const {
    typedef std::ratio_divide<Scale, NewScale> Quotient;
    return Unit<QuantityTag, NewType, NewScale>(static_cast<NewType>(value) *
                                                static_cast<NewType>(Quotient::num) /
                                                static_cast<NewType>(Quotient::den));
  }

  std::string ToString() const {
    const Quantity q(QuantityTag);
    return std::to_string(value) + utils::ToString<Scale>() + q.GetUnit();
  }

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
  Unit &operator*=(const Type &rhs) {
    value *= rhs;
    return *this;
  }

  // x / a
  Unit &operator/=(const Type &rhs) {
    value /= rhs;
    return *this;
  }

  // x + y
  friend Unit operator+(const Unit &lhs, const Unit &rhs) { return Unit(lhs.value + rhs.value); }

  // x - y
  friend Unit operator-(const Unit &lhs, const Unit &rhs) { return Unit(lhs.value - rhs.value); }

  // a * x
  friend Unit operator*(const Type &lhs, const Unit &rhs) { return Unit(lhs * rhs.value); }

  // x * a
  friend Unit operator*(const Unit &lhs, const Type &rhs) { return Unit(lhs.value * rhs); }

  // x / a
  friend Unit operator/(const Unit &lhs, const Type &rhs) { return Unit(lhs.value / rhs); }

 private:
  Type value;
};

}  // namespace unit

}  // namespace toolbox
