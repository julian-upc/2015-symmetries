/* Copyright (c) 2015
   Julian Pfeifle
   julian.pfeifle@upc.edu
   Constantin Fischer
   cfischer@mailbox.tu-berlin.de

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version: http://www.gnu.org/licenses/gpl.txt.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
--------------------------------------------------------------------------------
*/

#ifndef __ORBIT_H_
#define __ORBIT_H_

#include <set>
#include "types.h"
#include "generators.h"
#include <numeric>
#include <cmath>
# include <queue>
#include <bits/stl_algo.h>

struct Error_radius_comp {
    const NumberType error_radius = 0.00001;
    bool operator() (const VectorType& lhs, const VectorType& rhs) const { 
	for (size_t i=0; i<lhs.size(); ++i) {
	    if (fabs(lhs[i]-rhs[i]) > error_radius) {
		return lhs[i] < rhs[i];
	    }
	}
	
	return false;
    }
};

std::set<VectorType, Error_radius_comp> orbit(const GeneratorList& generators, const VectorType& v)	
{    
    if (generators[0].size() != v.size()) {
		throw DimensionMismatchException();
    }
    
    NumberType ip = 0;
    GeneratorList scaled_generators(generators.size(),generators[0].size());
    for (size_t i=0; i<generators.size(); ++i) {
		ip = 0;
		ip = std::inner_product(generators[i].begin(),generators[i].end(),generators[i].begin(), ip); 
		std::transform(generators[i].begin(), generators[i].end(), scaled_generators[i].begin(), std::bind1st(std::multiplies<NumberType>(),2/ip));	//type sensitive operation
    }    
    
    std::set<VectorType, Error_radius_comp> orbit({v});
    std::queue<VectorType> newPoints({v});
	VectorType mirrorPoint(v.size());
	NumberType weight = 0;
    do {
		mirrorPoint = newPoints.front();
		newPoints.pop();
		for (size_t i=0; i<generators.size(); ++i) {
			weight = 0;
			weight = std::inner_product(mirrorPoint.begin(), mirrorPoint.end(), generators[i].begin(), weight);
			for (size_t j=0; j<mirrorPoint.size(); ++j) {
				mirrorPoint[j] = mirrorPoint[j] - weight*scaled_generators(i,j);		  
			}
			if (orbit.insert(mirrorPoint).second) {
				newPoints.push(mirrorPoint);
			}
		}
	} while (!newPoints.empty());
	
   return orbit;
}


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
