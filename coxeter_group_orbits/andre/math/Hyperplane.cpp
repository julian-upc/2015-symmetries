#include <iostream>
#include "Hyperplane.h"
#include "Vector.h"

namespace math
{
	point Hyperplane::mirror( const point& p ) const {
		double tmp = 2 * Vector::stdScalarProduct( p, normal_vec );
		tmp /= Vector::stdScalarProduct(normal_vec, normal_vec);
		return p - tmp * normal_vec;
	}
}