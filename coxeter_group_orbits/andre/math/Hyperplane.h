#include <vector>
#include "vec2.h"

#ifndef HYPERPLANE_H_
#define HYPERPLANE_H_

/* define the mathematical namespace */
namespace math
{
	class Hyperplane
	{
	private:
		// the normal vector
		vec2 normal_vec;
		// a charactistic point on this hyperplane
		vec2 center;

	public:
		// creates a hyperplane with normal in Y direction through the center coordinates
		Hyperplane() : Hyperplane(ONE_Y){};

		// creates a hyperplane with given normal vector through the center coordinates
		Hyperplane(vec2 normal_vec) : Hyperplane(ZERO, normal_vec){};

		// creates a full specified hyperplane
		Hyperplane(vec2 center, vec2 normal_vec) : center(center), normal_vec(normal_vec) {};

		// mirroring a given point on this hyperplane
		vec2 mirror( const vec2& point ) const;
	};
}

#endif /* HYPERPLANE_H_ */