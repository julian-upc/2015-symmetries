#include "Universe.h"

namespace math {

	void Universe::addPlane(const Hyperplane& plane){
		planes.push_back(plane);
	}

	std::vector<vec2> Universe::getAllReflections(const vec2& point, int steps) const {
		std::vector<vec2> list(steps);
		list.push_back(point);

		int numOfPlanes = planes.size();

		for (int i = 0; i < steps; i++){
			list.push_back( planes[i % numOfPlanes].mirror( list.back() ) );
		}

		return list;
	}

}