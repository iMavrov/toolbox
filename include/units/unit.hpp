#pragma once

#include <ratio>
#include <string>

#include "quantity.hpp"

namespace toolbox {

namespace unit {

// template <typename Scale>
// std::string ToString() {
//   std::string result = std::to_string(value);
//   if (Scale::num == 1) {
//     switch (Scale::den) {
//       case 10: {
//         // deci
//       }
//       case 100: {
//         // centi
//       }
//       case 1000: {
//         // milli
//       }
//       case 1000000: {
//         // micro
//       }
//       case 1000000000: {
//         // nano
//       }
//       case 1000000000000: {
//         // pico
//       }
//     }
//   } else if (Scale::den == 1) {
//     switch (Scale::num) {
//       case 10:
//       // deca
//       case 100:
//       // hecta
//       case 1000:
//       // kilo
//       case 1000000:
//       // mega
//       case 1000000000:
//       // tera
//       case 1000000000000:
//     }
//   }
//   return result;
// }

/// @brief Linear unit of measurement.
/// @tparam QuantityTag SI
/// @tparam Type Type of stored value. Must be arithmetic.
/// @tparam Scale Value multiplier to get the standard unit.
template <unsigned int QuantityTag, typename Type = float, typename Scale = std::ratio<1>>
class Unit {
 public:
  static_assert(std::is_arithmetic<Type>::value, "Unit expects an arithmetic type for 'Type'");

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

  std::string ToString() {
    return std::to_string(value) + Quantity(static_cast<Quantity::Value>(QuantityTag)).GetUnit();
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

  // // Implementation of addition operator for different unit types
  // template <typename T1, typename U1, typename T2, typename U2>
  // auto operator+(const Unit<T1, U1> &lhs, const Unit<T2, U2> &rhs)
  //     -> Unit<decltype(std::declval<T1>() + std::declval<T2>()), void> {
  //   return Unit<decltype(std::declval<T1>() + std::declval<T2>()), void>(
  //       lhs.convert<decltype(std::declval<T1>() + std::declval<T2>())>() +
  //       rhs.convert<decltype(std::declval<T1>() + std::declval<T2>())>());
  // }

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

 protected:
  Type value;
};

}  // namespace unit

}  // namespace toolbox
