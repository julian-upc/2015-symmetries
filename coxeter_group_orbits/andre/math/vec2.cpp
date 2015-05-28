#include <math.h>
#include "vec2.h"

namespace math {

	vec2::vec2(){
		this->x = 0.0;
		this->y = 0.0;
	}

	vec2::vec2(const double& x, const double& y){
		this->x = x;
		this->y = y;
	}

	double vec2::norm() const {
		return sqrt(this->x * this->x + this->y * this->y);
	}

	vec2 operator+(const vec2& left, const vec2& right){
		return vec2( left.x+right.x, left.y+right.y);
	}

	vec2 operator-(const vec2& left, const vec2& right){
		return vec2(left.x - right.x, left.y - right.y);
	}

	vec2 vec2::operator*(double d) const {
		return vec2(this->x*d,this->y*d);
	}

	vec2 operator*(double d, const vec2& right){
		return right * d;
	}

	std::ostream& operator << (std::ostream& stream, const vec2& vector){
		stream << "(" << vector.x << "," << vector.y << ")";
		return stream;
	}
}