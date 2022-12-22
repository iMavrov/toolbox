#pragma once

#include <string>
#include <sstream>

namespace toolbox {

namespace si {

/// @brief Implements units of measure semantics to simple numerical values.
/// Uses SI base units of measure and their combinations.
///
/// @tparam T The numerical value type to store. Floating point type expected.
/// @tparam S Power of seconds.
/// @tparam M Power of meters.
/// @tparam KG Power of kilograms.
template <typename T, int S, int M, int KG>
class Unit {

public:
  static_assert(std::is_floating_point<T>::value, "Unit expects a floating point numeric type for 'T'");

  Unit() : value(0) { }

  explicit Unit(const T &value) : value(value) { }

  const T &Get() const { return value; }

  Unit operator+(const Unit &rhs) const {
    return Unit(value + rhs.Get());
  }

  Unit operator-(const Unit &rhs) const {
    return Unit(value - rhs.Get());
  }

  template<int OtherS, int OtherM, int OtherKG>
  Unit<T, S + OtherS, M + OtherM, KG + OtherKG> operator*(const Unit<T, OtherS, OtherM, OtherKG> &rhs) const {
    return Unit<T, S + OtherS, M + OtherM, KG + OtherKG>(value * rhs.Get());
  }

  template<int OtherS, int OtherM, int OtherKG>
  Unit<T, S - OtherS, M - OtherM, KG - OtherKG> operator/(const Unit<T, OtherS, OtherM, OtherKG> &rhs) const {
    return Unit<T, S - OtherS, M - OtherM, KG - OtherKG>(value / rhs.Get());
  }

  std::string ToString() const {
    std::stringstream buffer;
    buffer << *this;
    return buffer.str();
  }

private:
  static constexpr int SECONDS_POWER = S;
  static constexpr int METERS_POWER = M;
  static constexpr int KILOGRAMS_POWER = KG;

  T value;
};

static void PrintUnit(std::ostream& stream, const char *unit, int power, bool numerator) {
  if ((numerator && 0 < power) || (!numerator && power < 0)) {
    stream << unit;
    int absolutePower = abs(power);
    if (absolutePower != 1) {
      stream << '^' << absolutePower;
    }
  }  
}

template <typename T, int S, int M, int KG>
std::ostream& operator<<(std::ostream& stream, const Unit<T, S, M, KG> &other) {
  stream << other.Get();
  
  if (S != 0 || M != 0 || KG != 0) {
    stream << ' ';
  }

  PrintUnit(stream, "kg", KG, true);
  PrintUnit(stream, "m", M, true);
  PrintUnit(stream, "s", S, true);

  if (S < 0 || M < 0 || KG < 0) {
    stream << '/';
  }

  PrintUnit(stream, "kg", KG, false);
  PrintUnit(stream, "m", M, false);
  PrintUnit(stream, "s", S, false);

  return stream;
}

} // si

} // toolbox
