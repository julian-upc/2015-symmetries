#include <iostream>
#include "Hyperplane.h"

namespace math
{
	vec2 Hyperplane::mirror(const vec2& point) const {
		vec2 mirrored(0,0);
		
		double tmp = 2 * scalarProd( point, normal_vec );
		tmp /= scalarProd(normal_vec, normal_vec);
		
		//std::cout << point << "/TMP: " << tmp << std::endl;

		mirrored = point - tmp*normal_vec;

		return mirrored;
	}
}