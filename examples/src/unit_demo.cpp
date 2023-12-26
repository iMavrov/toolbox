#include <iostream>

#include "unit/unit.hpp"

using namespace toolbox::unit;

typedef Unit<Quantity::kLength> Meters;
typedef Unit<Quantity::kLength, float, std::milli> Millimeters;

enum CustomQuantity : unsigned int {
  kDegrees = Quantity::kCustom,
};
typedef Unit<kDegrees, int> Degrees;

int main(int argc, const char **argv) {
  const Meters a(1);
  std::cout << "a = " << a.ToString() << " = " << a.To<std::milli>().ToString() << " = "
            << a.To<std::kilo>().ToString() << std::endl;

  const Millimeters b(2);
  std::cout << "b = " << b.ToString() << std::endl;

  const auto c = a.To<std::milli>() + b;
  std::cout << "c = a + b = " << c.ToString() << std::endl;

  Quantity::RegisterCustomQuantity("deg");

  Degrees d(90);
  std::cout << "d = " << d.ToString() << std::endl;

  return 0;
}