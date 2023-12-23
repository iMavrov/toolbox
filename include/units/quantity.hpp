#pragma once

#include <stdexcept>
#include <string>
#include <vector>

namespace toolbox {

namespace unit {

/// @brief
class Quantity {
 public:
  enum Value : unsigned int {
    kTime,
    kLength,
    kMass,
    kCurrent,
    kTemperature,
    kSubstance,
    kIntensity
  };

  static constexpr unsigned int kCustom = kIntensity + 1u;

  static unsigned int RegisterCustomQuantity(const std::string &unit_name) {
    properties.emplace_back(Properties{unit_name});
    return properties.size() - 1u;
  }

  explicit Quantity(unsigned int unknown_value) : value(static_cast<Value>(unknown_value)) {}

  Quantity(Value value) : value(value) {}

  operator Value() const { return value; }

  bool IsStandard() const { return value < kCustom; }

  bool IsCustom() const { return kCustom <= value; }

  const std::string &GetUnit() const {
    if (value < properties.size()) {
      return properties[value].unit_name;
    }
    throw std::out_of_range("Unknown quantity!");
  }

  friend bool operator==(const Quantity &lhs, const Quantity &rhs) {
    return lhs.value == rhs.value;
  }

  friend bool operator!=(const Quantity &lhs, const Quantity &rhs) {
    return lhs.value != rhs.value;
  }

  friend bool operator==(const Quantity &lhs, const Value &rhs) { return lhs.value == rhs; }

  friend bool operator!=(const Quantity &lhs, const Value &rhs) { return lhs.value != rhs; }

  friend bool operator==(const Value &lhs, const Quantity &rhs) { return lhs == rhs.value; }

  friend bool operator!=(const Value &lhs, const Quantity &rhs) { return lhs != rhs.value; }

 private:
  struct Properties {
    std::string unit_name;
  };

  static std::vector<Properties> properties;

  Value value;
};

std::vector<Quantity::Properties> Quantity::properties = {{"s"}, {"m"},   {"g"}, {"A"},
                                                          {"K"}, {"mol"}, {"cd"}};

}  // namespace unit

}  // namespace toolbox
