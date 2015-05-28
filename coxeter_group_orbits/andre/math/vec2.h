#pragma once

#include <iostream>

namespace math {

	struct vec2 {
		double x;
		double y;

		// constructors
		vec2();
		vec2(const double& x, const double& y);

		friend vec2 operator+(const vec2& left, const vec2& right);
		friend vec2 operator-(const vec2& left, const vec2& right);

		vec2 operator*(double d) const;
		friend vec2 operator*(double d, const vec2& right);

		// euclidean norm
		double norm() const;

		// put this vec to a iostream
		friend std::ostream& operator << (std::ostream& stream, const vec2& vector);
	};

	static const vec2 ZERO(0, 0);
	static const vec2 ONE_X(1, 0);
	static const vec2 ONE_Y(0, 1);

	// standard scalar product
	static double scalarProd(const vec2& x, const vec2& y){
		return x.x * y.x + x.y * y.y;
	}
}