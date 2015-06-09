//
//  orbit.h
//  Coxeter_Orbit
//
//  Created by Robert Loewe on 07.06.15.
//  Copyright (c) 2015 Robert Loewe. All rights reserved.
//
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


#ifndef Coxeter_Orbit_orbit_h
#define Coxeter_Orbit_orbit_h


#include <vector>
#include <set>
#include <math.h>

class NotImplementedException : public std::exception {};

template <typename E>
class coxeterVector : public std::vector<E>{
    //using std::vector<E>::std::vector<E>;
};


typedef double NumberType;
typedef std::vector<NumberType> VectorType;
typedef std::vector<VectorType> GeneratorList;
typedef std::set<VectorType> Orbit;


std::set<VectorType> orbitSet;


VectorType vectorAddition(VectorType v1, VectorType v2){
    VectorType v = VectorType(v1.size());
    for(int i = 0; i < v1.size(); i++){
        v[i] = v1[i] + v2[i];
    }
    return v;
}

VectorType scalarMultiplication(double a, VectorType v1){
    VectorType v = VectorType(v1.size());
    for(int i = 0; i < v1.size(); i++){
        v[i] = a*v1[i];
    }
    return v;
}

double scalarProduct(VectorType v1, VectorType v2){
    double sum = 0;
    for(int i = 0; i < v1.size(); i++){
        sum += v1[i]*v2[i];
    }
    return sum;
}

VectorType reflection(VectorType normal, VectorType vector){
    VectorType reflected = VectorType(vector.size());
    double rs = (-2)*scalarProduct(vector, normal)/scalarProduct(normal, normal);
    reflected = vectorAddition(vector, scalarMultiplication(rs,normal));
    return reflected;
}

GeneratorList createMatrixB(int dim){
    GeneratorList Matrix;
    for (int i = 0; i < dim-1; i++){
        std::vector<NumberType> normal = VectorType(dim);
        normal[i] = 1;
        normal[i+1]= -1;
        Matrix.push_back(normal);
    }
    std::vector<NumberType> normal = VectorType(dim);
    normal[dim-1] = 1;
    Matrix.push_back(normal);
    return Matrix;
}

GeneratorList createMatrixA(int dim){
    GeneratorList Matrix;
    for (int i = 0; i < dim; i++){
        std::vector<NumberType> normal = VectorType(dim+1);
        normal[i] = 1;
        normal[i+1]= -1;
        Matrix.push_back(normal);
    }
    return Matrix;
}

GeneratorList createMatrixEsix(){
    GeneratorList Matrix = {
        {1,-1,0,0,0,0},
        {0,1,-1,0,0,0},
        {0,0,1,-1,0,0},
        {0,0,0,1,1,0},
        {-.5,-.5,-.5,-.5,-.5,sqrt(3)/2},
        {0,0,0,1,-1,0},
    };
        return Matrix;
}



GeneratorList simple_roots(char type, int dim)
{
    switch(type) {
        case 'B':
            return createMatrixB(dim);
        case 'A':
            return createMatrixA(dim);
            
        default:
            throw new NotImplementedException();
    }
}

void recursion(const GeneratorList& generators, VectorType v){
    for(int i = 0; i < generators.size(); i++){
        if (orbitSet.find(reflection(generators[i], v)) == orbitSet.end()) { //orbitSet contains reflection(generators[i], v)
            orbitSet.insert(reflection(generators[i], v));
            recursion(generators, reflection(generators[i], v));
        }
    }
}

Orbit orbit(const GeneratorList& generators, const VectorType& v)
{
    orbitSet.clear();
    orbitSet.insert(v);
    recursion(generators,v);
    return orbitSet;
}


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:





