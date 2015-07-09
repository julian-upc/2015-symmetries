/* Copyright (c) 2015
   Julian Pfeifle
   julian.pfeifle@upc.edu

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

#include <numeric>
#include <vector>
#include <functional>
#include <set>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <queue>
#include "types.h"
#include "generators.h"


   NumberType scalarProduct(const VectorType& x, const VectorType& y)
   {   
      NumberType sca = 0.0;

      return std::inner_product(x.begin(), x.end(), y.begin(), sca);
   }

   VectorType scalarMultiplication(const VectorType& p, const NumberType a)
   {   
      VectorType tmp (p);  
      for (VectorType::size_type i = 0; i != tmp.size(); i++){
         tmp[i] *= a;
      }
      return tmp;
   }

   VectorType vectorSubtraction(const VectorType& p, const VectorType& n)
   {
      VectorType tmp (p);  
      for (VectorType::size_type i = 0; i != n.size(); i++){
         tmp[i] -= n[i];
      }
      return tmp;
   }

   VectorType reflection(const VectorType& p, const VectorType& n)
   {
      VectorType p_ref = vectorSubtraction(p, scalarMultiplication(n, 2 * (scalarProduct(p,n) / scalarProduct(n,n))));

      return p_ref; 
   }

VectorType reflect( const VectorType& v, const VectorType& g )
{
	double gv = 0;
	double gg = 0;
	for( unsigned int i=0; i < v.size(); i++ )
	{
		gv += g[i] * v[i];
		gg += g[i] * g[i];
	}
	NumberType factor = -2.*gv/gg;
	VectorType sum(v);
	for( unsigned int i=0; i < v.size(); i++ )
		sum[i] += factor*g[i];
	return sum;
}

/*
   Orbit orbitConstructionRec(const GeneratorList& generators, const VectorType& v, Orbit& solution)
   {   
      VectorType ref;
     
      for(VectorType::size_type i = 0; i != generators.size(); i++){
         ref = reflection(v,generators[i]);      
         if(solution.find(ref) == solution.end()){
            solution.insert(ref);
            orbitConstructionRec(generators, ref, solution);
         }
      }
      return solution;
   }

   Orbit orbitRec(const GeneratorList& generators, const VectorType& v)
   {
      Orbit wholeOrbit;
      return orbitConstructionRec(generators, v, wholeOrbit);
   }*/

   bool impreciseEqual(const VectorType& v1, const VectorType& v2 )
   {
      for (VectorType::size_type i = 0; i != v1.size(); i++){
        if(  fabs(v1[i] - v2[i]) >  epsilon){
           return false; 
        }
      }
      return true;
   }


Orbit orbit(const GeneratorList& generators, const VectorType& v1)
{
	Orbit wholeOrbit = {v1};
	std::queue<VectorType,std::deque<VectorType> > toReflect;
	toReflect.push(v1);

	VectorType v;
	VectorType ref;
	Orbit::iterator nextIt; 
	std::pair<Orbit::iterator, bool> p;
	bool isFoundEqual = false;

	while( !toReflect.empty() )
	{
		v = toReflect.front();
		toReflect.pop();

		for( const auto g : generators )
		{
			ref = reflect(v,g);
			p = wholeOrbit.insert(ref);
			if(p.second) //if it was not inserted it is exactly equal to some vector already in the set, so we dont have to do anything
			{
				isFoundEqual = false;
				nextIt = p.first; //save pos of ref in p.first, because we might want to erase it
				nextIt++; //search to the right of ref
				while(!isFoundEqual && wholeOrbit.end() != nextIt && (*nextIt)[0] < ref[0] + epsilon)
				{
					if(impreciseEqual(*nextIt, ref))
					{
						isFoundEqual = true;
						wholeOrbit.erase(p.first);
					} 
					nextIt++;
				}
				nextIt = p.first; //search to the left of ref
				if(nextIt != wholeOrbit.begin())
				{
					nextIt--;
					while(!isFoundEqual && (*nextIt)[0] > ref[0] - epsilon)
					{
						if(impreciseEqual(*nextIt, ref))
						{
							isFoundEqual = true; 
							wholeOrbit.erase(p.first);
						}
						if(nextIt == wholeOrbit.begin())
							break;
						nextIt--;
					}
				}
				if( !isFoundEqual )
					toReflect.push(ref);
			}
		} 
	}
	return wholeOrbit;
}


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
