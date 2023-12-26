#pragma once

#include <sstream>
#include <string>

namespace toolbox {

namespace unit {

template <int S = 0, int M = 0, int KG = 0, int A = 0, int K = 0, int Mol = 0, int Cd = 0>
std::string GetTrivialName();

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

  std::string ToString() const {
    return std::to_string(value) + GetTrivialName<S, M, KG, A, K, Mol, Cd>();
  }

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

template <int S = 0, int M = 0, int KG = 0, int A = 0, int K = 0, int Mol = 0, int Cd = 0>
std::string GetTrivialName() {
  std::string numerator;
  std::string denominator;

  if constexpr (KG < 0) {
    AppendBaseUnitWithPower("kg", -KG, denominator);
  } else if constexpr (0 < KG) {
    AppendBaseUnitWithPower("kg", KG, numerator);
  }

  if constexpr (M < 0) {
    AppendBaseUnitWithPower("m", -M, denominator);
  } else if constexpr (0 < M) {
    AppendBaseUnitWithPower("m", M, numerator);
  }

  if constexpr (S < 0) {
    AppendBaseUnitWithPower("s", -S, denominator);
  } else if constexpr (0 < S) {
    AppendBaseUnitWithPower("s", S, numerator);
  }

  if constexpr (A < 0) {
    AppendBaseUnitWithPower("A", -A, denominator);
  } else if constexpr (0 < A) {
    AppendBaseUnitWithPower("A", A, numerator);
  }

  if constexpr (K < 0) {
    AppendBaseUnitWithPower("K", -K, denominator);
  } else if constexpr (0 < K) {
    AppendBaseUnitWithPower("K", K, numerator);
  }

  if constexpr (Mol < 0) {
    AppendBaseUnitWithPower("mol", -Mol, denominator);
  } else if constexpr (0 < Mol) {
    AppendBaseUnitWithPower("mol", Mol, numerator);
  }

  if constexpr (Cd < 0) {
    AppendBaseUnitWithPower("cd", -Cd, denominator);
  } else if constexpr (0 < Cd) {
    AppendBaseUnitWithPower("cd", Cd, numerator);
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
