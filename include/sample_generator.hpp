#pragma once

/// Standard headers
#include "math.h"
#include "stdlib.h"

/// Project headers
#include "math_utils.hpp"
#include "vector2d.hpp"

namespace toolbox {

class SampleGenerator {

public:
  SampleGenerator(int seed) {
    srand(seed);
  }

  bool getBooleanSample() const {
    return (rand() % 2) == 0;
  }

  int getIntegerSample(const int minValue = 0, const int maxValue = RAND_MAX) const {
    return minValue + rand() % (maxValue - minValue);
  }

  float getFloatSample(const float minValue = 0.0f, const float maxValue = 1.0f) const {
    static const float INVERSE_RAND_MAX_FLOAT = 1.0f / RAND_MAX;
    float unitRangeSample = INVERSE_RAND_MAX_FLOAT * rand();
    return minValue + unitRangeSample * (maxValue - minValue);
  }

  Vector getDiskSample() const {
    float phi = getFloatSample(0.0f, Chaos::DOUBLE_PI);
    return Vector(cosf(phi), sinf(phi));
  }

  Vector getSemidiskSample() const {
    float phi = getFloatSample(0.0f, Chaos::PI);
    return Vector(cosf(phi), sinf(phi));
  }

  Vector getConeSample(float halfConeAngleRadians) const {
    float theta = getFloatSample(-halfConeAngleRadians, halfConeAngleRadians);
    return Vector(sinf(theta), cosf(theta));
  }

  Vector getCosineLobeSample() const {
    float sinTheta = getFloatSample(-1.0f, 1.0f);
    return Vector(sinTheta, sqrtf(1.0f - sinTheta * sinTheta));
  }

  // From Global Illumination Compendium, page 20, (36)
  Vector getCosineLobeSample(float cosPower) const {
    float r1 = getFloatSample(0.0f, Chaos::DOUBLE_PI);
    float r2 = getFloatSample();
    float n = cosPower;

    float z = powf(r2, 1.0f / (n + 1.0f));
    float x = cosf(r1) * sqrtf(1.0f - z * z);

    // Use only the x and z coordinates of the original 3D vector
    Vector projectedSample = Vector(x, z);
    // Normalize the projected vector, effectively extending it to the unit semi-disk
    projectedSample.normalize();

    return projectedSample;
  }

  // PBRT
  float getBeerSample(float tau) const {
    float uniformSample = getFloatSample();
    return -logf(1.0f - uniformSample) / tau;
  }

  // https://www.astro.umd.edu/~jph/HG_note.pdf
  Vector getHenyeyGreensteinSample(float g) const {
    float s = getFloatSample(-1.0f, 1.0f);
    float mu = s;

    if (EPSILON < fabsf(g)) {
      float term0 = (1.0f - g * g) / (1.0f + g * s);
      mu = (1.0f + g * g - term0 * term0) / (2.0f * g);
    }

    float cosTheta = clamp(mu, -1.0f, 1.0f);
    float sinTheta = sqrtf(1.0f - cosTheta * cosTheta);

    float phi = getFloatSample(0.0f, Chaos::DOUBLE_PI);
    Vector projectedSample =  Vector(cosf(phi) * sinTheta, cosTheta);
    projectedSample.normalize();

    return projectedSample;
  }
};

} // namespace toolbox
