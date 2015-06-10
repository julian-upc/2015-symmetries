//
//  main.cpp
//  CoxeterOrbit
//
//  Created by Jonas Neukamm on 04.06.15.
//  Copyright (c) 2015 LovisJonas. All rights reserved.
//

#include <iostream>
#include <set>
#include "orbit.h"
#include <math.h>

const static char letter = 'G';

int main(int argc, const char * argv[]) {
	for (int i = 2; i < 7; i++){
		GeneratorList list(simple_roots(letter, i));
		std::cout << "Generator Size: " << list.size() << '\n';
		for (size_t j = 0; j < list.size(); j++)
			std::cout << list[j].print() << '\n';
		VectorType vec(i);
		if (letter == 'I') {
			vec[0] = 0.2124;
			vec[1] = 1.423;
		}
		else if (letter == 'G'){
			vec[0] = 0.2124;
			vec[1] = 1.423;
			vec[2] = 1.111;
		}
		else{
			for (int j = 0; j < i; j++)
				vec[j] = (i*j + 0.7)*pow(-1, j);
		}
		std::cout << "Vector: " << vec.print() << '\n';
		if (letter == 'B')
		{
			NumberType should = pow(2, i);
			for (int j = 1; j <= i; j++)
				should *= j;
			std::cout << "max orbit: 2^n*n! = " << should << '\n';
		}
		Orbit orb = orbit(list, vec);
		std::cout << "Orbit Size: " << orb.size() << '\n';
		//  std::cout << orb.setRepresentation();
	}
	return 0;
}
