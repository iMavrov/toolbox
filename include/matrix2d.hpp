#pragma once

/// Project headers
#include "vector2d.hpp"

namespace toolbox {

// | a c |
// | b d |
class Matrix {

public:
	float a;
	float b;
	float c;
	float d;

	Matrix(const float inputA = 1.0f, const float inputB = 0.0f, const float inputC = 0.0f, const float inputD = 1.0f)
		: a(inputA), b(inputB), c(inputC), d(inputD) {
	}

	Matrix(const Vector &inputVector) {
		Vector normal = inputVector;
		normal.normalize();
		Vector tangent = normal.getPerpendicularVector();
		a = tangent.x;
		b = tangent.y;
		c = normal.x;
		d = normal.y;
	}
};

inline Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix result;
	result.a = lhs.a * rhs.a + lhs.c * rhs.b;
	result.b = lhs.b * rhs.a + lhs.d * rhs.b;
	result.c = lhs.a * rhs.c + lhs.c * rhs.d;
	result.d = lhs.b * rhs.c + lhs.d * rhs.d;
	return result;
}

inline Vector operator*(const Matrix& lhs, const Vector& rhs) {
	Vector result;
	result.x = lhs.a * rhs.x + lhs.c * rhs.y;
	result.y = lhs.b * rhs.x + lhs.d * rhs.y;
	return result;
}

} // namespace toolbox
