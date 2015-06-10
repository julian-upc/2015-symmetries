//
//  impreciseVector.h
//  CoxeterOrbit
//
//  Created by Jonas Neukamm on 04.06.15.
//  Copyright (c) 2015 LovisJonas. All rights reserved.
//

#ifndef CoxeterOrbit_epsilonVector_h
#define CoxeterOrbit_epsilonVector_h

#include <vector>
#include <math.h>

const static double epsilon = 0.01;

typedef double E;

class EpsilonVector : public std::vector<E>
{
private:

	E scalarProduct(const EpsilonVector& a, const EpsilonVector& b) const
	{
		E c = 0;
		for (size_t i = 0; i < a.size(); i++)
			c += a[i] * b[i];
		return c;
	}

public:

	EpsilonVector() {}

	explicit EpsilonVector(int dim)
		: std::vector<E>(dim)
	{}


	template <typename T>
	EpsilonVector(std::initializer_list<T> init)
		: std::vector<E>(init)
	{}


	EpsilonVector mirror(EpsilonVector normal) const
	{
		double scalar = scalarProduct(normal, normal);
		long s = this->size();
		std::vector<std::vector<double>> matrix(s, EpsilonVector(s));
		EpsilonVector mir(s);
		for (int i = 0; i < s; i++){
			matrix[i][i] += 1;
			for (int j = 0; j < s; j++){
				matrix[i][j] += (-2)*normal[i] * normal[j] / scalar;
				mir[i] += matrix[i][j] * this->at(j);
			}
		}
		return mir;
	}

	bool operator==(const EpsilonVector& rhs) const
	{
		EpsilonVector a(*this);
		for (size_t i = 0; i < rhs.size(); i++) {
			a[i] -= rhs[i];
		}
		return (scalarProduct(a, a) < epsilon);
	}

	bool operator!=(const EpsilonVector& rhs) const
	{
		return !(*this == rhs);
	}

	std::string print() const
	{
		std::string output;
		for (size_t i = 0; i < this->size(); i++){
			std::ostringstream os;
			os << this->at(i);
			std::string str = os.str();
			output.append(str);
			output.append(" ");
		}
		return output;
	}


}; // Klasse zuende.

#endif
