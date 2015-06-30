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
#include "orbit.h"
#include <iostream>
//#include <algorithm>
//#include "stdlib.h"

//determining the current RAM usage (from http://stackoverflow.com/questions/63166/how-to-determine-cpu-and-memory-consumption-from-inside-a-process)
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int parseLine(char* line){
        int i = strlen(line);
        while (*line < '0' || *line > '9') line++;
        line[i-3] = '\0';
        i = atoi(line);
        return i;
    }
    

     int getValue(){ //Note: this value is in KB!
        FILE* file = fopen("/proc/self/status", "r");
        int result = -1;
        char line[128];
    

        while (fgets(line, 128, file) != NULL){
            if (strncmp(line, "VmRSS:", 6) == 0){
                result = parseLine(line);
                break;
            }
        }
        fclose(file);
        return result;
    }

int main(int argc, char *argv[])
{  
    std::ifstream iFile(argv[1]);
    std::ofstream oFile(argv[2]);
    std::string input = "";
    char type;
    int dim;
    VectorType point;
    bool print_flag = false;
    if (argc == 4) {
	std::string flag(argv[3]);
	print_flag = flag  == "-p";
    }
    
    //read the input file
    if (iFile.is_open()) {
	//read the type and dimension
	if (iFile.good()) {
	    std::getline(iFile, input);
	    std::stringstream ss(input);
	    if (ss.good()) {
		char t;
		if (ss >> t) {
		    type = t;
		}
		int d;
		if (ss >> d) {
		    dim = d;
		}
	    }
	}
	//read the input point
	if (iFile.good()) {
	    std::getline(iFile, input);
	    std::stringstream ss(input);
	    long double coo = 0;
	    while (ss.good()) {
		if (ss >> coo) {
		    point.push_back(coo);
		}
	    }
	}
    }
        
	std::set<VectorType, Error_radius_comp> orb = orbit(simple_roots(type,dim),point);

	//generate the output
	if (oFile.is_open()) {
	    oFile << orb.size() << std::endl;
	    if (print_flag) {
		for (auto p : orb) {
		    for (size_t i=0; i<p.size(); ++i) {
			oFile << p[i] << " ";
		    }
		    oFile << std::endl;
		}
	    }
	}
	
	std::cout << "orbit size = " << orb.size() << std::endl;
	std::cout << "RAM usage = " << getValue()/1000 << "mB" << std::endl;
    
    return 0;      
}