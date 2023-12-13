#include <cassert>
#include <cstdio>

#include "units/unit.hpp"

typedef toolbox::unit::Unit<toolbox::unit::Quantity::kTime> Duration;
typedef toolbox::unit::Unit<toolbox::unit::Quantity::kLength> Distance;
typedef toolbox::unit::Unit<toolbox::unit::Quantity::kMass> Weight;

enum CustomQuantity : unsigned int {
  kDegrees = toolbox::unit::Quantity::kCustom,
};
typedef toolbox::unit::Unit<kDegrees> Degrees;

int main(int argc, const char **argv) {
  const auto result = toolbox::unit::Quantity::RegisterCustomQuantity("deg");
  assert(result == kDegrees);

  Distance a;
  printf("%s\n", a.ToString().c_str());

  Degrees d;
  printf("%s\n", d.ToString().c_str());

  // toolbox::unit::Unit<toolbox::unit::kDistance, int> a(1);
  // printf("%d\n", a.To<std::milli>().Get());
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