#pragma once

#include "si_unit.hpp"

namespace toolbox {

namespace unit {

typedef SIUnit<> Measureless;
typedef SIUnit<1> Duration;
typedef SIUnit<0, 1> Distance;
typedef SIUnit<0, 0, 1> Mass;
typedef SIUnit<0, 0, 0, 1> Current;
typedef SIUnit<0, 0, 0, 0, 1> Temperature;
typedef SIUnit<0, 0, 0, 0, 0, 1> Substance;
typedef SIUnit<0, 0, 0, 0, 0, 0, 1> LuminousIntensity;

typedef SIUnit<-1> Frequency;
template <>
std::string GetTrivialName<-1>() {
  return "Hz";
}

typedef SIUnit<0, 2> Area;
typedef SIUnit<0, 3> Volume;

typedef SIUnit<-1, 1> Velocity;
typedef SIUnit<-2, 1> Acceleration;

typedef SIUnit<-2, 1, 1> Force;
template <>
std::string GetTrivialName<-2, 1, 1>() {
  return "N";
}

typedef SIUnit<-2, -1, 1> Pressure;
template <>
std::string GetTrivialName<-2, -1, 1>() {
  return "Pa";
}

typedef SIUnit<-2, 2, 1> Energy;
template <>
std::string GetTrivialName<-2, 2, 1>() {
  return "J";
}

typedef SIUnit<-3, 2, 1> Power;
template <>
std::string GetTrivialName<-3, 2, 1>() {
  return "W";
}

}  // namespace unit

}  // namespace toolbox
