#pragma once

#include <vector>
#include "Hyperplane.h"
#include "vec2.h"

namespace math {

	class Universe {
	private:
		std::vector<Hyperplane> planes;

	public:
		Universe() : planes( std::vector<Hyperplane>() ){};

		Universe(std::vector<Hyperplane> planes) : planes(planes){};

		// TODO dont know if it is correct
		Universe(const Universe& uni) : planes(uni.planes){};

		void addPlane(const Hyperplane& plane);

		std::vector<vec2> getAllReflections(const vec2& point, int steps) const;
	};

}