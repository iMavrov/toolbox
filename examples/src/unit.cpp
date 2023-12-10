#include <cstdio>

#include "units/unit.hpp"

int main(int argc, const char **argv) {
  toolbox::unit::Unit<float> a(1);
  printf("%f\n", a.To<std::milli>().Get());
  printf("%f\n", a.Get());
  printf("%f\n", a.To<std::ratio<13>>().Get());

  toolbox::unit::Unit<float, std::milli> b(2);

  auto c = a + b.To<std::ratio<1>>();
  printf("%f\n", c.Get());

  toolbox::unit::Unit<int> i(static_cast<int>(a.Get()));
  printf("%d\n", i.To<std::ratio<1, 13>>().Get());

  return 0;
}