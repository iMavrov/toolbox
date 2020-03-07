#pragma once

/// Project headers
#include "vector2d.hpp"

namespace toolbox {

inline float distance(const Vector &rhs, const Vector &lhs) {
	Vector difference = rhs - lhs;
	return difference.length();
}

inline float dot(const Vector &rhs, const Vector &lhs) {
	return rhs.x * lhs.x + rhs.y * lhs.y;
}

template <typename T>
inline T min(const T &lhs, const T &rhs) {
	return (lhs < rhs) ? lhs : rhs;
}

template <typename T>
inline T max(const T &lhs, const T &rhs) {
	return (lhs < rhs) ? rhs : lhs;
}

template <typename T>
inline T clamp(const T &value, const T &lowerLimit, const T &upperLimit) {
	return min(max(value, lowerLimit), upperLimit);
}

inline float lnf(const float x) {
	return logf(x) * INV_LG_E;
}

} // namespace toolbox
