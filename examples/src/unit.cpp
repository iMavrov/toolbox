#include <cassert>
#include <cstdio>

#include <ratio>
#include <string>

#include "units/unit.hpp"

typedef toolbox::unit::Unit<toolbox::unit::Quantity::kTime> Duration;
typedef toolbox::unit::Unit<toolbox::unit::Quantity::kLength> Distance;
typedef toolbox::unit::Unit<toolbox::unit::Quantity::kMass> Weight;

enum CustomQuantity : unsigned int {
  kDegrees = toolbox::unit::Quantity::kCustom,
};
typedef toolbox::unit::Unit<kDegrees> Degrees;

int main(int argc, const char **argv) {
  // const auto result = toolbox::unit::Quantity::RegisterCustomQuantity("deg");
  // assert(result == kDegrees);

  // Distance a;
  // printf("%s\n", a.ToString().c_str());

  // Degrees d;
  // printf("%s\n", d.ToString().c_str());

  // printf("%s\n", toolbox::utils::ToString<std::milli>().c_str());

  Distance a(1);
  printf("%s\n", a.ToString().c_str());
  printf("%s\n", a.To<std::milli>().ToString().c_str());
  printf("%s\n", a.To<std::kilo>().ToString().c_str());
  // printf("%d\n", a.Get());
  // printf("%d\n", a.To<std::ratio<13>>().Get());

  // toolbox::unit::Unit<int, std::milli> b(2);

  // auto c = a + b.To<std::ratio<1>>();
  // printf("%d\n", c.Get());

  // toolbox::unit::Unit<float> i(static_cast<float>(a.Get()));
  // printf("%f\n", i.To<std::ratio<1, 13>>().Get());

  // toolbox::unit::Unit<> d(42);

  return 0;
}