/* Copyright (c) 2015
   Julian Pfeifle
   julian.pfeifle@upc.edu
   meike.hatzel@tu-berlin.de

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

#include "orbit.h"
#include <fstream>


int main()
{   
	GeneratorList generators;
	VectorType v;
	input("file.txt", v, generators);
	Orbit generatedOrbit = orbit(generators, v);
	//sanityCheck(generatedOrbit.size(),"file.txt");
	std::ofstream file;
	file.open ("out.txt");
	out(file, generatedOrbit, true);

}

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
