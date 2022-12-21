#pragma once

namespace toolbox {

class Color {

public:
  float r;
  float g;
  float b;

  Color() : r(0.0f), g(0.0f), b(0.0f) {
  }

  explicit Color(const float greyScale) : r(greyScale), g(greyScale), b(greyScale) {
  }

  Color(const float inputR, const float inputG, const float inputB) : r(inputR), g(inputG), b(inputB) {
  }

  void set(const float inputR, const float inputG, const float inputB) {
    r = inputR;
    g = inputG;
    b = inputB;
  }

  Color operator+(const Color &other) const {
    return Color(r + other.r, g + other.g, b + other.b);
  }

  Color operator+(const float other) const {
    return Color(r + other, g + other, b + other);
  }

  Color operator*(const Color &other) const {
    return Color(r * other.r, g * other.g, b * other.b);
  }

  Color operator*(const float other) const {
    return Color(r * other, g * other, b * other);
  }

  Color operator-(const Color &other) const {
    return Color(r - other.r, g - other.g, b - other.b);
  }

  Color operator/(const Color &other) const {
    return Color(r / other.r, g / other.g, b / other.b);
  }
};

inline Color operator*(const float lhs, const Color &rhs) {
  return Color(lhs * rhs.r, lhs * rhs.g, lhs * rhs.b);
}

inline Color min(const Color &lhs, const Color &rhs) {
  return Color((lhs.r < rhs.r) ? lhs.r : rhs.r, (lhs.g < rhs.g) ? lhs.g : rhs.g, (lhs.b < rhs.b) ? lhs.b : rhs.b);
}

inline Color max(const Color &lhs, const Color &rhs) {
  return Color((lhs.r < rhs.r) ? rhs.r : lhs.r, (lhs.g < rhs.g) ? rhs.g : lhs.g, (lhs.b < rhs.b) ? rhs.b : lhs.b);
}

inline Color clamp(const Color &argument, const Color &lowerLimit, const Color &upperLimit) {
  return min(max(argument, lowerLimit), upperLimit);
}

} // namespace toolbox