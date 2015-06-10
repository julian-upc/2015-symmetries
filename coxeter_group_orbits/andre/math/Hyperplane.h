#include <vector>
#include "Vector.h"

#ifndef HYPERPLANE_H_
#define HYPERPLANE_H_

/* define the mathematical namespace */
namespace math
{
	// differentiate direction and point vectors
	typedef Vector vector;
	typedef Vector point;

	class Hyperplane
	{
	private:
		// the normal vector
		vector normal_vec;
		// a charactistic point on this hyperplane
		point center;

	public:
		// creates a hyperplane with normal in Y direction through the center coordinates
		Hyperplane() 
			: Hyperplane(three_D::X){};

		// creates a hyperplane with given normal vector through the center coordinates
		Hyperplane( const vector& normal_vec ) 
			: Hyperplane(three_D::ZERO, normal_vec){};

		// creates a full specified hyperplane
		Hyperplane( const point& center, const vector& normal_vec ) 
			: center(center)
			, normal_vec(normal_vec) {};

		// mirroring a given point on this hyperplane
		point mirror( const point& p ) const;
	};
}

#endif /* HYPERPLANE_H_ */