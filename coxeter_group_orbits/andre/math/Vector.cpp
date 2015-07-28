#include <math.h>
#include "Vector.h"

namespace math {
	double Vector::norm() const {
		double sum = 0;
		for (int i = 0; i < dimension; i++){
			sum += values[i] * values[i];
		}
		return sqrt(sum);
	}

	Vector Vector::operator*(double d) const {
		Vector result = Vector(this->values);
		for (int i = 0; i < result.dimension; i++)
			result.values[i] *= d;
		return result;
	}

	Vector operator*(double d, const Vector& right){
		Vector result = Vector(right.values);
		for (int i = 0; i < result.dimension; i++)
			result.values[i] *= d;
		return result;
	}
	
	Vector operator+(const Vector& left, const Vector& right){
		Vector result = Vector(left.values);
		for (int i = 0; i < result.dimension; i++)
			result.values[i] += right.values[i];
		return result;
	}

	Vector operator-(const Vector& left, const Vector& right){
		Vector result = Vector(left.values);
		for (int i = 0; i < result.dimension; i++)
			result.values[i] -= right.values[i];
		return result;
	}

	bool Vector::operator==(const Vector& vec) const {
		for (int i = 0; i < this->dimension; i++)
			if (this->values[i] != vec.values[i]) return false;
		return true;
	}

	std::ostream& operator << (std::ostream& stream, const Vector& vec){
		stream << "(";
		for (unsigned int i = 0; i < vec.values.size() - 1; i++){
			stream << vec.values[i] << ",";
		}
		stream << vec.values.back() << ")";
		return stream;
	}

	std::ostream& operator << (std::ostream& stream, const std::queue<Vector>& que){
		std::queue<Vector> copy(que);
		
		stream << "(";
		while ( copy.size() >= 1 ){
			stream << copy.front() << ",";
			copy.pop();
		}
		stream << que.back() << ")";
		return stream;
	}

}