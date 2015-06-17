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
#include <sys/time.h>

typedef unsigned long long timestamp_t;
static timestamp_t
get_timestamp (){
    struct timeval now;
    gettimeofday (&now, NULL);
    return now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}




class NotImplementedException : public std::exception {};


typedef double E;

const static E epsilon = 0.0001;

class coxeterVector : public std::vector<E>{
    
public:
    
    coxeterVector(){}
    
    explicit coxeterVector(int dim): std::vector<E>(dim){}
    
    template <typename T>
    coxeterVector(std::initializer_list<T> init)
    : std::vector<E>(init) {}
    
    

    bool operator==(const coxeterVector& rhs) const
    {
        coxeterVector a(*this);
        for ( int i = 0; i < rhs.size() ; i++) {
            if ( a[i] <  rhs[i] - epsilon  ||  a[i] > rhs[i] + epsilon )
                return false;
        }
        return true;
    }
    
    bool operator < (const coxeterVector& rhs) const
    {
        for ( int i = 0; i < rhs.size() ; i++) {
            if ( this->at(i) < rhs[i] - epsilon ) {
                return true;
            } else {
                if ( this->at(i) > rhs[i] + epsilon )
                    return false;
            }
        }
        return false;
    }
    
    friend std::ostream& operator << (std::ostream& os, const coxeterVector& v)
    {
        for (const auto& x : v)
            os << x << " ";
        return os;
    }

    
    
};


typedef double NumberType;
typedef coxeterVector VectorType;
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
        VectorType normal (dim);
        normal[i] = 1.;
        normal[i+1]= -1.;
        Matrix.push_back(normal);
    }
    VectorType normal (dim);
    normal[dim-1] = 1.;
    Matrix.push_back(normal);
    return Matrix;
}

GeneratorList createMatrixA(int dim){
    GeneratorList Matrix;
    for (int i = 0; i < dim; i++){
        VectorType normal (dim+1);
        normal[i] = 1.;
        normal[i+1]= -1.;
        Matrix.push_back(normal);
    }
    return Matrix;
}

GeneratorList createMatrixE(int dim)
{
    GeneratorList Matrix;
    for ( int i = 0 ; i < dim-2 ; i++ ) {
        VectorType vec(dim);
        vec[i]=1;
        vec[i+1]=-1;
        Matrix.push_back(vec);
    }
    if (dim == 6)
        Matrix.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,sqrt(3)/2.});
    if (dim ==  7)
        Matrix.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,sqrt(2)/2.});
    if (dim == 8)
        Matrix.push_back({-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5});
    VectorType vec1 (dim); vec1[dim-3] = 1; vec1[dim-2] = 1;
    Matrix.push_back(vec1);
    return Matrix;
}


GeneratorList createMatrixF(){
    GeneratorList Matrix={  {0.5,-0.5,-0.5,-0.5} ,
                            {0.,1.,-1.,0.},
                            {0.,0.,1.,-1.},
                            {0.,0.,0.,1.}
                         };
    return Matrix;
}

GeneratorList createMatrixG(){
    GeneratorList Matrix= {  {0.,1.,-1.},
                            {1.,-2.,1.} };
    return Matrix;
}

GeneratorList createMatrixI(int dim)
{
    GeneratorList Matrix {{1., 0.},{0.,1.}};
    double cosine = cos(M_PI/dim);
    Matrix[1][0]= cosine/sqrt(1.0-pow(cosine, 2));
    return Matrix;
}

GeneratorList createMatrixD(){
    GeneratorList Matrix ={
        {1.,-1.,0.,0.},
        {0.,1.,-1.,0.},
        {0.,0.,1.,-1.},
        {0.,0.,1.,1.}
    };
    return Matrix;
}


GeneratorList simple_roots(char type, int dim)
{
    switch(type) {
        case 'A':
            if (dim > 0)
                return createMatrixA(dim);
            else throw new NotImplementedException();
        case 'B':
            if (dim > 0)
                return createMatrixB(dim);
            else throw new NotImplementedException();
        case 'C':
            if (dim > 0)
                return createMatrixB(dim);
            else throw new NotImplementedException();
        case 'D':
            if (dim > 4) throw new NotImplementedException();
            else throw new NotImplementedException();
        case 'E':
            if (dim == 6)
                return createMatrixE(dim);
            else if (dim == 7)
                return createMatrixE(dim);
            else if (dim == 8)
                return createMatrixE(dim);
            else throw new NotImplementedException();
        case 'F':
            if (dim == 4) return createMatrixF();
            throw new NotImplementedException();
        case 'G':
            if (dim == 2) return createMatrixG();
            throw new NotImplementedException();
        case 'H':
            if (dim == 2) throw new NotImplementedException();
            if (dim == 3) throw new NotImplementedException();
            if (dim == 4) throw new NotImplementedException();
            else throw new NotImplementedException();
        case 'I':
            if (dim < 1) throw new NotImplementedException();
            else return createMatrixI(dim);
        default:
            throw new NotImplementedException();
    }
}


Orbit orbit(const GeneratorList& generators, const VectorType& v )
{
    Orbit orb;
    Orbit tmpPoints {v};
    while (tmpPoints.empty() == false ){
        Orbit::iterator it = tmpPoints.begin();
        VectorType vec = *it;
        tmpPoints.erase(it);
        if ( std::get<1>(orb.insert(vec)) ){
            //std::cout << vec << '\n';
            for (int i = 0 ; i < generators.size() ; i++)
                tmpPoints.insert(reflection(generators[i], vec));
        } // endif
    } // endwhile
    return orb;
}



/*void recursion(const GeneratorList& generators, VectorType v, int counter){
    for(int i = 0; i < generators.size(); i++){
        //std:: cout << i << std::endl;
        if (orbitSet.find(reflection(generators[i], v)) == orbitSet.end()) { //orbitSet contains reflection(generators[i], v)
            orbitSet.insert(reflection(generators[i], v));
            
            counter += 1;
            //std::cout << "counter " << counter << std::endl;
            recursion(generators, reflection(generators[i], v), counter);
        }
    }
}

Orbit orbit(const GeneratorList& generators, const VectorType& v)
{
    orbitSet.clear();
    orbitSet.insert(v);
    recursion(generators,v,0);
    return orbitSet;
}*/


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:





