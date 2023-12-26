#include <iostream>

#include "units/si_units.hpp"

using namespace toolbox::unit;

typedef SIUnit<1, -1, 0> Pace;

int main(int argc, const char **argv) {
  const Distance x(1);
  const Distance y(2);
  const Distance z(3);
  std::cout << x.ToString() << std::endl;

  const Duration time(1);
  std::cout << time.ToString() << std::endl;

  const Mass mass(1);
  std::cout << mass.ToString() << std::endl;

  const auto area = x * y;
  std::cout << area.ToString() << std::endl;

  const auto volume = area * z;
  std::cout << volume.ToString() << std::endl;

  const auto velocity = x / time;
  std::cout << velocity.ToString() << std::endl;

  const auto distance = velocity * time;
  std::cout << distance.ToString() << std::endl;

  const auto pace = Measureless(1) / velocity;
  std::cout << pace.ToString() << std::endl;

  const auto acceleration = velocity / time;
  std::cout << acceleration.ToString() << std::endl;

  const auto force = mass * acceleration;
  std::cout << force.ToString() << std::endl;

  const auto pressure = force / area;
  std::cout << pressure.ToString() << std::endl;

  const auto energy = force * distance;
  std::cout << energy.ToString() << std::endl;

  const auto power = energy / time;
  std::cout << power.ToString() << std::endl;

  return 0;
}
