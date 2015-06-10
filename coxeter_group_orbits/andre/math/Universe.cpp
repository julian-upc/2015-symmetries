#include "Universe.h"
#include <iostream>

namespace math {
	Orbit Universe::getOrbit(const point& p, unsigned steps) {
		orbit.clear();
		this->p = p;
		
		std::vector<point> points;
		points.push_back(p);
		orbit.insert(p);

		point curr;
		point reflected;
		size_t old_size;

		for (unsigned i = 0; i < points.size() && i < steps; i++){
			curr = points[i];
			for (unsigned j = 0; j < planes.size() && j + i < steps; j++){
				reflected = planes[j].mirror(curr);
				old_size = orbit.size();
				orbit.insert(reflected);
				if (old_size != orbit.size())
					points.push_back(reflected);
			}
		}

		return orbit;
	}

	std::ostream& operator << (std::ostream& stream, const Orbit& o){
		stream << "Orbit Size is " << o.size() << std::endl;
		stream << "Orbit: {";
		
		unsigned i = 0;
		for ( auto& it = o.begin(); it != o.end(); ++it, i++){
			stream << *it;
			if (i < o.size()-1) stream << ",";
		}

		stream << "}";
		return stream;
	}
}