#include <iostream>

#include "si/unit.hpp"

using namespace toolbox::si;

typedef Unit<float, 0, 0, 0> Measureless;
typedef Unit<float, 1, 0, 0> Duration;
typedef Unit<float, 0, 1, 0> Distance;
typedef Unit<float, 0, 0, 1> Weight;

typedef Unit<float, 0, 2, 0> Area;
typedef Unit<float, 0, 3, 0> Volume;

typedef Unit<float, -1, 1, 0> Velocity;
typedef Unit<float, -2, 1, 0> Acceleration;

typedef Unit<float, 1, -1, 0> Pace;

int main(int argc, const char **argv) {
  const Distance lengthA(1);
  const Distance lengthB(2);
  const Distance lengthC(3);

  std::cout << lengthA << std::endl;

  const Duration duration(1);

  std::cout << duration << std::endl;

  const auto area = lengthA * lengthB;

  std::cout << area << std::endl;

  const auto volume = area * lengthC;

  std::cout << volume << std::endl;

  const auto velocity = lengthA / duration;

  std::cout << velocity << std::endl;

  const auto distance = velocity * duration;

  std::cout << distance << std::endl;

  const auto pace = Measureless(1) / velocity;

  std::cout << pace << std::endl;

  const auto acceleration = velocity / duration;

  std::cout << acceleration << std::endl;
  
  return 0;
}
