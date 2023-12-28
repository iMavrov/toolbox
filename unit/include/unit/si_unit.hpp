#pragma once

#include <sstream>
#include <string>

namespace toolbox {

namespace unit {

template <typename U>
std::string GetTrivialUnitName();

/// @brief Implements units of measure semantics for simple numerical values.
/// Uses SI base units of measure and their combinations.
/// @tparam S Power of seconds.
/// @tparam M Power of meters.
/// @tparam KG Power of kilograms.
/// @tparam A Power of amperes.
/// @tparam K Power of kelvins.
/// @tparam Mol Power of moles.
/// @tparam Cd Power of candelas.
/// @tparam T The numerical value type to store. Floating point type expected.
template <int S = 0, int M = 0, int KG = 0, int A = 0, int K = 0, int Mol = 0, int Cd = 0,
          typename T = float>
class SIUnit {
 public:
  static_assert(std::is_floating_point<T>::value,
                "SI unit expects a floating point numeric type for 'T'");

  static constexpr int SECONDS_POWER = S;
  static constexpr int METERS_POWER = M;
  static constexpr int KILOGRAMS_POWER = KG;
  static constexpr int AMPERES_POWER = A;
  static constexpr int KELVINS_POWER = K;
  static constexpr int MOLES_POWER = Mol;
  static constexpr int CANDELAS_POWER = Cd;
  typedef T Type;

  SIUnit() : value(0) {}

  explicit SIUnit(const T &value) : value(value) {}

  T Get() const { return value; }

  std::string ToString() const { return std::to_string(value) + GetTrivialUnitName<SIUnit>(); }

  SIUnit operator+(const SIUnit &rhs) const { return SIUnit(value + rhs.value); }

  SIUnit operator-(const SIUnit &rhs) const { return SIUnit(value - rhs.value); }

  template <int RS, int RM, int RKG, int RA, int RK, int RMol, int RCd>
  SIUnit<S + RS, M + RM, KG + RKG, A + RA, K + RK, Mol + RMol, Cd + RCd, T> operator*(
      const SIUnit<RS, RM, RKG, RA, RK, RMol, RCd, T> &rhs) const {
    return SIUnit<S + RS, M + RM, KG + RKG, A + RA, K + RK, Mol + RMol, Cd + RCd, T>(value *
                                                                                     rhs.Get());
  }

  template <int RS, int RM, int RKG, int RA, int RK, int RMol, int RCd>
  SIUnit<S - RS, M - RM, KG - RKG, A - RA, K - RK, Mol - RMol, Cd - RCd, T> operator/(
      const SIUnit<RS, RM, RKG, RA, RK, RMol, RCd, T> &rhs) const {
    return SIUnit<S - RS, M - RM, KG - RKG, A - RA, K - RK, Mol - RMol, Cd - RCd, T>(value /
                                                                                     rhs.Get());
  }

 private:
  T value;
};

void AppendBaseUnitWithPower(const std::string &base_unit, int power, std::string &result) {
  if (!result.empty()) {
    result += ".";
  }
  result += base_unit;
  if (1 < power) {
    result += std::to_string(power);
  }
}

template <typename U>
std::string GetTrivialUnitName() {
  std::string numerator;
  std::string denominator;

  if constexpr (U::KILOGRAMS_POWER < 0) {
    AppendBaseUnitWithPower("kg", -U::KILOGRAMS_POWER, denominator);
  } else if constexpr (0 < U::KILOGRAMS_POWER) {
    AppendBaseUnitWithPower("kg", U::KILOGRAMS_POWER, numerator);
  }

  if constexpr (U::METERS_POWER < 0) {
    AppendBaseUnitWithPower("m", -U::METERS_POWER, denominator);
  } else if constexpr (0 < U::METERS_POWER) {
    AppendBaseUnitWithPower("m", U::METERS_POWER, numerator);
  }

  if constexpr (U::SECONDS_POWER < 0) {
    AppendBaseUnitWithPower("s", -U::SECONDS_POWER, denominator);
  } else if constexpr (0 < U::SECONDS_POWER) {
    AppendBaseUnitWithPower("s", U::SECONDS_POWER, numerator);
  }

  if constexpr (U::AMPERES_POWER < 0) {
    AppendBaseUnitWithPower("A", -U::AMPERES_POWER, denominator);
  } else if constexpr (0 < U::AMPERES_POWER) {
    AppendBaseUnitWithPower("A", U::AMPERES_POWER, numerator);
  }

  if constexpr (U::KELVINS_POWER < 0) {
    AppendBaseUnitWithPower("K", -U::KELVINS_POWER, denominator);
  } else if constexpr (0 < U::KELVINS_POWER) {
    AppendBaseUnitWithPower("K", U::KELVINS_POWER, numerator);
  }

  if constexpr (U::MOLES_POWER < 0) {
    AppendBaseUnitWithPower("mol", -U::MOLES_POWER, denominator);
  } else if constexpr (0 < U::MOLES_POWER) {
    AppendBaseUnitWithPower("mol", U::MOLES_POWER, numerator);
  }

  if constexpr (U::CANDELAS_POWER < 0) {
    AppendBaseUnitWithPower("cd", -U::CANDELAS_POWER, denominator);
  } else if constexpr (0 < U::CANDELAS_POWER) {
    AppendBaseUnitWithPower("cd", U::CANDELAS_POWER, numerator);
  }

  if (!denominator.empty()) {
    if (numerator.empty()) {
      numerator = "1/";
    } else {
      numerator += "/";
    }
  }

  return numerator + denominator;
}

}  // namespace unit

}  // namespace toolbox
