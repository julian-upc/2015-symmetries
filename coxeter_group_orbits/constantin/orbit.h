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

#include <set>
#include "types.h"
#include "generators.h"
#include <numeric>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stl_algo.h>
#include <boost/concept_check.hpp>
#include <iostream>

// //determining the current RAM usage (from http://stackoverflow.com/questions/63166/how-to-determine-cpu-and-memory-consumption-from-inside-a-process)
// #include "stdlib.h"
// #include "stdio.h"
// #include "string.h"
// 
// int parseLine(char* line){
//         int i = strlen(line);
//         while (*line < '0' || *line > '9') line++;
//         line[i-3] = '\0';
//         i = atoi(line);
//         return i;
//     }
//     
// 
//      int getValue(){ //Note: this value is in KB!
//         FILE* file = fopen("/proc/self/status", "r");
//         int result = -1;
//         char line[128];
//     
// 
//         while (fgets(line, 128, file) != NULL){
//             if (strncmp(line, "VmRSS:", 6) == 0){
//                 result = parseLine(line);
//                 break;
//             }
//         }
//         fclose(file);
//         return result;
//     }

// GeneratorList normalize_generators(const GeneratorList& generators) 
// {
//     GeneratorList newGens = generators;
//     for (size_t i=0; i<generators.size(); ++i) {
// 	long double euclidLength = 0;
// 	euclidLength = std::inner_product(generators[i].begin(), generators[i].end(), generators[i].begin(), euclidLength); //type mismatch?
// 	euclidLength = std::sqrt(euclidLength);
// 	for (size_t j=0; j<generators[i].size(); ++j) {
// 	    newGens(i,j) = generators(i,j)/euclidLength;
// 	} 
//     }
//     return newGens;
// }

struct Error_radius_comp {
//     const long double error_radius;
    const long double error_radius = 0.00001;
//     Error_radius_comp(/*long double eps*/); /*: error_radius(eps) {}*/  
    bool operator() (const VectorType& lhs, const VectorType& rhs) const { 
	for (size_t i=0; i<lhs.size(); ++i) {
	    if (lhs[i]-rhs[i] > error_radius || rhs[i]-lhs[i] > error_radius) {
		return lhs < rhs;
	    }
	}
	return false;
    }
};

std::set<VectorType, Error_radius_comp> orbit(const GeneratorList& generators, const VectorType& v/*, const long double eps=0*/)	//is it possible to make the comparator variable?
{
//     const GeneratorList normGens = normalize_generators(generators);
    
    if (generators[0].size() != v.size()) {
	throw DimensionMismatchException();
    }
  
    std::set<VectorType, Error_radius_comp> orbit({v});
    std::set<VectorType> points1({v}), points2;
    std::set<VectorType> *currPoints = &points1, *nextPoints = &points2;
    
    GeneratorList scaled_generators(generators.size(),generators[0].size());
    for (size_t i=0; i<generators.size(); ++i) {
	NumberType ip = 0;
	ip = std::inner_product(generators[i].begin(),generators[i].end(),generators[i].begin(), ip); 
	std::transform(generators[i].begin(), generators[i].end(), scaled_generators[i].begin(), std::bind1st(std::multiplies<NumberType>(),2/ip));	//type sensitive operation
    }    
    
//     for (size_t i=0; i<generators.size(); ++i) {
// 	std::cout << "gen " << i << " = [ ";
// 	for (size_t j=0; j<generators[i].size(); ++j) {
// 	    std::cout << generators(i,j) << " "; 
// 	}
// 	NumberType ip = 0;
// 	ip = std::inner_product(generators[i].begin(),generators[i].end(),generators[i].begin(), ip);
// 	std::cout << "] - " << 2/ip << " -> [ ";
// 	for (size_t j=0; j<scaled_generators[i].size(); ++j) {
// 	    std::cout << scaled_generators(i,j) << " "; 
// 	}
// 	std::cout << "]" << std::endl;
//     }
    
//     size_t wordlength = 0;
    do {
// 	++wordlength;
	for (auto iter=(*currPoints).begin(); iter!=(*currPoints).end(); iter = (*currPoints).erase(iter)) {
	    for (size_t i=0; i<generators.size(); ++i) {
		std::vector<long double> newPoint((*iter).size());
		NumberType weight = 0;	
		weight = std::inner_product((*iter).begin(), (*iter).end(), generators[i].begin(), weight);
		for (size_t j=0; j<(*iter).size(); ++j) {
		    newPoint[j] = (*iter)[j] - weight*scaled_generators(i,j);
		}
		if (orbit.insert(newPoint).second) {
		    (*nextPoints).insert(newPoint);
		}
	    }
	}	
	std::swap(currPoints,nextPoints);
// 	std::cout << "iteration " << wordlength << " processed using " << getValue()/1000 << "mb of RAM" << std::endl;
// 	std::cout << orbit.size() << std::endl;
    } while (!(*currPoints).empty());
   
   return orbit;
}


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
