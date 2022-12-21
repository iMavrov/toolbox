#pragma once

/// Standard headers
#include "math.h" // sqrtf

/// Project headers
#include "math_constants.hpp"

namespace toolbox {

class Vector {

public:
  float x;
  float y;

  Vector();
  
  explicit Vector(const float input);

  Vector(const float inputX, const float inputY);
  
  void set(const float inputX, const float inputY);

  void normalize();
  
  float length() const;
  
  Vector getPerpendicularVector() const;

  Vector operator-() const;

  Vector operator+(const float rhs) const;

  Vector operator+(const Vector &rhs) const;

  Vector operator-(const float rhs) const;

  Vector operator-(const Vector &rhs) const;

  Vector operator*(const float rhs) const;

  Vector operator*(const Vector &rhs) const;

  Vector operator/(const float rhs) const;

  Vector operator/(const Vector &rhs) const;

  Vector& operator+=(const float rhs);

  Vector& operator+=(const Vector &rhs);

  Vector& operator-=(const float rhs);

  Vector& operator-=(const Vector &rhs);

  Vector& operator*=(const float rhs);

  Vector& operator*=(const Vector &rhs);

  Vector& operator/=(const float rhs);

  Vector& operator/=(const Vector &rhs);
};

inline Vector::Vector()
  : x(0.0f), y(0.0f) {
}

inline Vector::Vector(const float input)
  : x(input), y(input) {
}

inline Vector::Vector(const float inputX, const float inputY) 
  : x(inputX), y(inputY) {
}

inline void Vector::set(const float inputX, const float inputY) {
  x = inputX;
  y = inputY;
}

inline void Vector::normalize() {
  float vectorLength = length();
  if (EPSILON < vectorLength) {
    x /= vectorLength;
    y /= vectorLength;
  }
}

inline float Vector::length() const {
  return sqrtf(x * x + y * y);
}

inline Vector Vector::getPerpendicularVector() const {
  return Vector(y, -x);
}

inline Vector Vector::operator-() const {
  return Vector(-x, -y);
}

inline Vector Vector::operator+(const float rhs) const {
  return Vector(x + rhs, y + rhs);
}

inline Vector Vector::operator+(const Vector &rhs) const {
  return Vector(x + rhs.x, y + rhs.y);
}

inline Vector operator+(const float lhs, const Vector &rhs) {
  return Vector(lhs + rhs.x, lhs + rhs.y);
}

inline Vector Vector::operator-(const float rhs) const {
  return Vector(x - rhs, y - rhs);
}

inline Vector Vector::operator-(const Vector &rhs) const {
  return Vector(x - rhs.x, y - rhs.y);
}

inline Vector operator-(const float lhs, const Vector &rhs) {
  return Vector(lhs - rhs.x, lhs - rhs.y);
}

inline Vector Vector::operator*(const float rhs) const {
  return Vector(x * rhs, y * rhs);
}

inline Vector Vector::operator*(const Vector &rhs) const {
  return Vector(x * rhs.x, y * rhs.y);
}

inline Vector operator*(const float lhs, const Vector &rhs) {
  return Vector(lhs * rhs.x, lhs * rhs.y);
}

inline Vector Vector::operator/(const float rhs) const {
  return Vector(x / rhs, y / rhs);
}

inline Vector Vector::operator/(const Vector &rhs) const {
  return Vector(x / rhs.x, y / rhs.y);
}

inline Vector operator/(const float lhs, const Vector &rhs) {
  return Vector(lhs / rhs.x, lhs / rhs.y);
}

inline Vector& Vector::operator+=(const float rhs) {
  x += rhs;
  y += rhs;
  return *this;
}

inline Vector& Vector::operator+=(const Vector &rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}

inline Vector& Vector::operator-=(const float rhs) {
  x -= rhs;
  y -= rhs;
  return *this;
}

inline Vector& Vector::operator-=(const Vector &rhs) {
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

inline Vector& Vector::operator*=(const float rhs) {
  x *= rhs;
  y *= rhs;
  return *this;
}

inline Vector& Vector::operator*=(const Vector &rhs) {
  x *= rhs.x;
  y *= rhs.y;
  return *this;
}

inline Vector& Vector::operator/=(const float rhs) {
  x /= rhs;
  y /= rhs;
  return *this;
}

inline Vector& Vector::operator/=(const Vector &rhs) {
  x /= rhs.x;
  y /= rhs.y;
  return *this;
}

} // namespace toolbox
