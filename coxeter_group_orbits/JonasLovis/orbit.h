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

#include <vector>
#include <set>
#include <math.h>
#include <sstream>
#include <string>
#include "epsilonVector.h"

class NotImplementedException : public std::exception {};


// PI for cosine function & Radius,eps to compare points in Orbit
typedef double NumberType;
typedef EpsilonVector VectorType;
typedef std::vector<VectorType> GeneratorList;
typedef std::set<VectorType> Orbit;
typedef GeneratorList MatrixType;

GeneratorList give_A(int dim)
{
    GeneratorList list;
    for (int i = 0 ; i < dim ; i++ ) {
        VectorType vec (dim+1);
        vec[i]=1;
        vec[i+1]=-1;
        list.push_back(vec);
    }
    return list;
}

GeneratorList give_B(int dim)
{
    GeneratorList list;
    for ( int i = 0 ; i < dim-1 ; i++ ) {
        VectorType vec (dim);
        vec[i] = 1;
        vec[i+1]=-1;
        list.push_back(vec);
    }
    VectorType vec (dim);
    vec[dim-1]=1;
    list.push_back(vec);
    return list;
}

GeneratorList give_C(int dim)
{
	GeneratorList list = give_A(dim - 1);
	VectorType v(dim);
	v[dim - 1] = 2;
	list.push_back(v);
	return list;
}

GeneratorList give_D(int dim)
{
	/*
	Read rowwise, these simple root vectors are
	1 -1  0 0 ... 0 0
	0  1 -1 0 ... 0 0
	...
	0  0  0 0 ... 1 -1
	0  0  0 0 ... 1  1
	The indexing of the Dynkin diagram is
	n-2
	/
	0 - 1 - 2 - ... - n-3
	\
	n-1
	*/
	VectorType v(dim);
	v[dim - 2] = v[dim - 1] = 1;
	GeneratorList list = give_A(dim - 1);
	list.push_back(v);
	return list;
}

GeneratorList give_E(int dim)
{
    GeneratorList list;
    for ( int i = 0 ; i < dim-2 ; i++ ) {
       VectorType vec(dim);
        vec[i]=1;
        vec[i+1]=-1;
        list.push_back(vec);
    }
    if (dim == 6)
        list.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,sqrt(3)/2.});
    if (dim ==  7)
        list.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,sqrt(2)/2.});
    if (dim == 8)
        list.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5});
    VectorType vec1 (dim); vec1[dim-3] = 1; vec1[dim-2] = 1;
    list.push_back(vec1);
    return list;
}

GeneratorList give_F(){
    GeneratorList list={  {0.5,-0.5,-0.5,-0.5} ,
                            {0.,1.,-1.,0.},
                            {0.,0.,1.,-1.},
                            {0.,0.,0.,1.}
                        };
    return list;
}

GeneratorList give_G()
{
    GeneratorList list = {  {0.,1.,-1.},
                            {1.,-2.,1.} };
    return list;
}


GeneratorList give_H(int dim){
	const NumberType tau(0.5 + 0.5 * sqrt(5)); // golden ratio
	GeneratorList list;
	if (dim = 3){
		VectorType v(3);
		v[0] = 2;
		list.push_back(v);
		VectorType v1(3);
		v1[0] = -tau;
		v1[1] = tau - 1;
		v1[2] = -1;
		list.push_back(v1);
		VectorType v2(3);
		v2[2] = 2;
		list.push_back(v2);
	}
	if (dim = 4){
		VectorType v(4);
		v[0] = (1 + tau) * 0.5;
		v[1] = v[2] = v[3] = (1 - tau) * 0.5;
		list.push_back(v);
		VectorType v1(4);
		v1[0] = -1;
		v1[1] =  1;
		list.push_back(v1);
		VectorType v2(4);
		v2[1] = -1;
		v2[2] = 1;
		list.push_back(v2);
		VectorType v3(4);
		v3[2] = -1;
		v3[3] = 1;
		list.push_back(v3);
	}
	return list;
}

GeneratorList give_I(int dim)
{
    GeneratorList list {{1., 0.},{0.,1.}};
    double cosine = cos(M_PI/dim);
    list[1][0]= cosine/sqrt(1.0-pow(cosine, 2));
    return list;
}

GeneratorList simple_roots(char type, int dim)
{
    switch(type) {
        case 'A':
            if (dim > 0)
                return give_A(dim);
            else throw new NotImplementedException();
        case 'B':
            if (dim > 0)
                return give_B(dim);
            else throw new NotImplementedException();
        case 'C':
            if (dim > 0)
                return give_C(dim);
            else throw new NotImplementedException();
        case 'D':
            if (dim > 4) give_D(dim);
			else if ( dim > 0 ) give_A(dim);
            	else throw new NotImplementedException();
        case 'E':
            if (dim == 6)
                return give_E(dim);
            else if (dim == 7)
                return give_E(dim);
            else if (dim == 8)
                return give_E(dim);
            else throw new NotImplementedException();
        case 'F':
            if (dim == 4) return give_F();
            throw new NotImplementedException();
        case 'G':
            if (dim == 2) return give_G();
            throw new NotImplementedException();
        case 'H':
            if (dim == 2) throw new NotImplementedException();
            if (dim == 3) throw new NotImplementedException();
            if (dim == 4) throw new NotImplementedException();
            else throw new NotImplementedException();
        case 'I':
            if (dim < 1) throw new NotImplementedException();
            else return give_I(dim);
        default:
            throw new NotImplementedException();
    }
}

Orbit orbit(const GeneratorList& generators, const VectorType& v )
{
    Orbit orb;
    GeneratorList newPoints {v};
    while (newPoints.empty() == false ){
        VectorType vec = newPoints.back();
        newPoints.pop_back();
        if ( std::get<1>(orb.insert(vec)) ){
            //std::cout << vec << '\n';
            for (int i = 0 ; i < generators.size() ; i++)
                newPoints.push_back( vec.mirror(generators[i]) );
        } // endif
    } // endwhile
    return orb;
}

#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:


