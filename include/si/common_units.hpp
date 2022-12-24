#pragma once

#include "si/unit.hpp"

namespace toolbox {

namespace si {

#ifndef TB_PRECISION
  #define TB_LOCALLY_DEFINED_PRECISION
  #define TB_PRECISION float
#endif

typedef Unit<TB_PRECISION, 0, 0, 0> Measureless;

typedef Unit<TB_PRECISION, 1, 0, 0> Duration;
typedef Unit<TB_PRECISION, 0, 1, 0> Distance;
typedef Unit<TB_PRECISION, 0, 0, 1> Weight;

typedef Unit<TB_PRECISION, 0, 2, 0> Area;
typedef Unit<TB_PRECISION, 0, 3, 0> Volume;

typedef Unit<TB_PRECISION, -1, 1, 0> Velocity;
typedef Unit<TB_PRECISION, -2, 1, 0> Acceleration;

#ifdef TB_LOCALLY_DEFINED_PRECISION
  #undef TB_PRECISION
#endif

} // si

} // toolbox
