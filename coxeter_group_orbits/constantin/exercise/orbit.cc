/* Copyright (c) 2015
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

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <cmath>
#include <set>

int main()
{  
    std::ifstream iFile("input");
    std::ofstream oFile("output");
    std::string input = "";
    std::vector<double> point;
    int wordLength;
    std::vector<std::vector<double> > normals;
    double test;
    
    //read the input file
    if (iFile.is_open()) {
	//read the input point
	if (iFile.good()) {
	    std::getline(iFile, input);
	    std::stringstream ss(input);
	    double coo = 0;
	    while (ss.good()) {
		if (ss >> coo) {
		    point.push_back(coo);
		}
	    }
	}
	//read the input word length
	if (iFile.good()) {
	    std::getline(iFile, input);
	    std::stringstream ss(input);
	    int l;
	    while (ss.good()) {
		if (ss >> l) {
		    wordLength = l;
		}
	    }
	}
	//read the input normal vectors
	while (iFile.good()) {
	    std::getline(iFile, input);
	    std::stringstream ss(input);
	    double coo = 0;
	    std::vector<double> n;
	    while (ss.good()) {
		if (ss >> coo) {
		    n.push_back(coo);
		}
	    }
	    normals.push_back(n);
	}
    }
    normals.pop_back();
    
    //normalize the normal vectors
    for (int i=0; i<normals.size(); ++i) {
	double euclidLength = 0;
	euclidLength = std::inner_product(normals[i].begin(), normals[i].end(), normals[i].begin(), euclidLength); //return type equals the type of the start value
	euclidLength = std::sqrt(euclidLength);
	for (int j=0; j<normals[i].size(); ++j) {
	    normals[i][j] = normals[i][j] / euclidLength;
	} 
    }
    
    //generate all words in the generators given by the normal vectors with length up to wordLength

    //generate the orbit (up to wordLength)
    std::set<std::vector<double> > orbit = {point};
    for (int i=0; i<wordLength; ++i) {
	std::set<std::vector<double> > newSet;
	for (auto p : orbit) {
	    for (auto n : normals) {
		std::vector<double> newPoint(p.size());
		double weight = 0;
		weight = std::inner_product(p.begin(), p.end(), n.begin(), weight); 
		for (int j=0; j<p.size(); ++j) {
		    newPoint[j] = p[j] - 2*weight*n[j];
		}
		newSet.insert(newPoint);
	    }
	}
	orbit.insert(newSet.begin(), newSet.end());
    }
    
    
    //test the read input files by writing the processed data into the output file
    if (oFile.is_open()) {
	oFile << "reference point:" << std::endl;
	for (int i=0; i<point.size(); ++i) {
	    oFile << point[i] << " ";
	}
	oFile << std::endl << "number of iterated refelctions:" << std::endl << wordLength << std::endl << "normalized normal vectors:";
	for (int i=0; i<normals.size(); ++i) {
	    oFile << std::endl;
	    for (int j=0; j<normals[i].size(); ++j) {
		oFile <<  normals[i][j] << " ";
	    }
	}
	oFile << std::endl << "orbit:" << std::endl;
	for (auto p : orbit) {
	    for (int i=0; i<p.size(); ++i) {
		oFile << p[i] << " ";
	    }
	    oFile << std::endl;
	}
    }
     
    return 0;   
}