//
//  impreciseVector.h
//  CoxeterOrbit
//
//  Created by Jonas Neukamm on 04.06.15.
//  Copyright (c) 2015 LovisJonas. All rights reserved.
//

#ifndef __epsilonVector_h
#define __epsilonVector_h

#include <vector>
#include <math.h>

const static double epsilon = 0.0000001;

typedef double E;

class EpsilonVector : public std::vector<E>
{
private:

	E scalarProduct(const EpsilonVector& b) const
	{
		E c = 0;
		for (int i = 0; i < b.size(); i++)
			c += this->operator[](i) * b[i];
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

	EpsilonVector mirror(const EpsilonVector& normal) const
	{
		double scalar = normal.scalarProduct(normal);
		EpsilonVector mir(this->size());
		for (int i = 0; i < this->size(); i++){
			for (int j = 0; j < this->size(); j++){
				mir[i] += normal[i] * normal[j] * this->operator[](j);
			}
			mir[i] *= (-2) / (scalar);
			mir[i] += this->operator[](i);
		}
		return mir;
	}

	bool operator==(const EpsilonVector& rhs) const
	{
		EpsilonVector a(*this);
		for (int i = 0; i < rhs.size(); i++) {
			if (a[i] <  rhs[i] - epsilon || a[i] > rhs[i] + epsilon)
				return false;
		}
		return true;
	}

	// Comparison operator to be used by our Orbit.
	bool operator < (const EpsilonVector& rhs) const
	{
		for (int i = 0; i < rhs.size(); i++) {
			if ((*this)[i] < rhs[i] - epsilon) {
				return true;
			}
			else {
				if ((*this)[i] > rhs[i] + epsilon)
					return false;
			}
		}
		return false;
	}

	friend std::ostream& operator << (std::ostream& os, const EpsilonVector& v)
	{
		for (const auto& x : v)
			os << x << " ";
		return os;
	}
}; // Klasse zuende.

#endif
