#include <vector>
#include <queue>
#include <iostream>

#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace math {
	// mathematical exception
	class InvalidDimensionError : public std::exception {};

	/* A mathematical Vector */
	class Vector {
	private:
		// entries
		std::vector<double> values;
		// dimension
		int dimension;

	public:
		// default
		Vector(){};

		// general constructor
		Vector(std::vector<double> values) 
			: values(values)
			, dimension(values.size())
		{};

		// simple one dimensional vector
		Vector(double x)
			: values( std::vector<double>(1) )
			, dimension(1)
		{
			values[0] = x;
		};

		// simple twp dimensional vector
		Vector(double x, double y)
			: values(std::vector<double>(2))
			, dimension(2)
		{
			values[0] = x;
			values[1] = y;
		}

		// simple three dimensional vector
		Vector(double x, double y, double z)
			: values(std::vector<double>(3))
			, dimension(3)
		{
			values[0] = x;
			values[1] = y;
			values[2] = z;
		}

		// calculate the euclidean norm of this vector
		double norm() const;

		// returns the values of this vector
		std::vector<double> getValues() const{
			return values;
		}

		// returns the dimension of this vector
		int getDimension() const {
			return dimension;
		}

		/* OPERATOR OVERLOADS */
		Vector operator*(double d) const;

		// equality opeartor
		bool operator==(const Vector& vec) const;

		// some mathematical operators
		friend Vector operator*(double d, const Vector& right);
		friend Vector operator+(const Vector& left, const Vector& right);
		friend Vector operator-(const Vector& left, const Vector& right);

		// like toString() in java
		friend std::ostream& operator << (std::ostream& stream, const Vector& vec);
		friend std::ostream& operator << (std::ostream& stream, const std::queue<Vector>& que);

		// returns the standard scalar product value of <vec1, vec2>
		static double stdScalarProduct(const Vector& vec1, const Vector& vec2){
			if (vec1.dimension != vec2.dimension) throw InvalidDimensionError();
			double sum = 0;
			for (int i = 0; i < vec1.dimension; i++)
				sum += vec1.values[i] * vec2.values[i];
			return sum;
		}
	};

	/* A Hash-function for a vector based on bernstein hash */
	struct VectorHash {
		std::size_t operator() (const Vector& v) const {
			std::vector<double> values = v.getValues();
			unsigned h = 0;
			for (unsigned i = 0; i < values.size(); i++){
				h = 33 * h ^ (int)(values[i]*1000);
			}
			return h;
		}
	};
	
	// some constants for 3D and 2D vectors
	namespace three_D {
		static const Vector ZERO= Vector(0, 0, 0);
		static const Vector X	= Vector(1, 0, 0);
		static const Vector Y	= Vector(0, 1, 0);
		static const Vector Z	= Vector(0, 0, 1);
	}

	namespace two_D {
		static const Vector ZERO= Vector(0, 0);
		static const Vector X	= Vector(1, 0);
		static const Vector Y	= Vector(0, 1);
	}
}

#endif /* _VECTOR_H_ */