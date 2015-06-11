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

const static char letter = 'A';

int main(int argc, const char * argv[]) {
    for (int i =  3; i < 10; i++){
        GeneratorList list(simple_roots(letter, i));
        std::cout << "Generator Size: " << list.size() << '\n';
        for ( int j = 0 ; j < list.size() ; j++)
            std::cout << list[j] << '\n';
        VectorType vec (i);
        if ( letter == 'I') {
            vec = {0.2124, 1.423};
        if ( letter == 'G'){
            vec = {0.2124, 1.423 , 12.22};
        }
        if ( letter == 'B' ) {
                for ( int j = 0 ; j < i ; j++)
                    vec[j] = (i*j+0.7)*pow(-1, j);
        }
        if ( letter == 'A' ) {
            for ( int j = 0 ; j < i ; j++){
                vec[j] = (i*j+0.7)*pow(-1, j);
            }
            vec.push_back(0.2);
        }
        
        std::cout << "Vector: " << vec << '\n';
        if ( letter == 'B' )
        {
            NumberType should = pow(2,i);
            for ( int j = 1 ; j <= i ; j++ )
                should *= j;
            std::cout << "max orbit: 2^n*n! = " << should <<'\n';
        }
        Orbit orb = orbit(list, vec);
        /*
        Orbit::iterator it;
        for (it = orb.begin(); it != orb.end(); ++it)
        {
            std::cout << *it << '\n';
        }
        */
        
        std::cout << "Orbit Size: " << orb.size() << '\n';
        //  std::cout << orb.setRepresentation();
    }
    return 0;
    }
