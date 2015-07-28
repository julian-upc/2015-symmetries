#include <queue>
#include <vector>
#include <unordered_set>
#include "Hyperplane.h"
#include "Vector.h"

#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

// mathematical object
namespace math {

	// an orbit is a unordered set of points without multiple entries
	typedef std::unordered_set<point, VectorHash> Orbit;

	/* a universe contains multiple hyperplanes */
	class Universe {
	private:
		// the hyperplanes
		std::vector<Hyperplane> planes;
		// a global variable to hold current orbits
		Orbit orbit;
		point p;

	public:
		// default constructor
		Universe() {};

		// construct a universe by a set of hyperplanes
		Universe(const std::vector<Hyperplane>& planes) : planes(planes){};

		// construct a copy of another universe
		Universe(const Universe& uni) : planes(uni.planes){};

		// adds a new hyperplane to this universe
		void addPlane(const Hyperplane& plane){
			planes.push_back(plane);
		}

		/* returns the orbit by given point */
		Orbit getOrbit(const point& p, unsigned steps);

		friend std::ostream& operator << (std::ostream& stream, const Orbit& o);
	};

}

#endif /* _UNIVERSE_H_ */