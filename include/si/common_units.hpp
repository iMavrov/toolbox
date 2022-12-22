#pragma once

#include "si/unit.hpp"

namespace toolbox {

namespace si {

typedef Unit<float, 0, 0, 0> Measureless;

typedef Unit<float, 1, 0, 0> Duration;
typedef Unit<float, 0, 1, 0> Distance;
typedef Unit<float, 0, 0, 1> Weight;

typedef Unit<float, 0, 2, 0> Area;
typedef Unit<float, 0, 3, 0> Volume;

typedef Unit<float, -1, 1, 0> Velocity;
typedef Unit<float, -2, 1, 0> Acceleration;

} // si

} // toolbox
