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

const static char letter = 'D';

int main(int argc, const char * argv[]) {
    for (int i =  6; i < 7; i++){
        VectorType vec (i);
        if ( letter == 'I') {
            vec = {0.2124, 1.423};
        }
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
            NumberType should = 1;
            for ( int j = 1 ; j <= i ; j++ )
                should *= j;
            std::cout << "max orbit: n+1! = " << should <<'\n';
        }
        if ( letter == 'B' )
        {
            for ( int j = 0 ; j < i ; j++){
                vec[j] = (i*j+0.7)*pow(-1, j);
            }
            std::cout << letter << '\n';
            NumberType should = pow(2,i);
            for ( int j = 1 ; j <= i ; j++ )
                should *= j;
            std::cout << "max orbit: 2^n*n! = " << should <<'\n';
        }
        if ( letter == 'D' )
        {
            for ( int j = 0 ; j < i ; j++){
                vec[j] = (i*j+0.7)*pow(-1, j);
            }
        }
        if ( letter == 'E' ){
            vec = {0.121 , -0.0001 , 1. , 1.1 , 1. , 0.43 };
        }
        GeneratorList list(simple_roots(letter, i));
        std::cout << "Generator Size: " << list.size() << '\n';
        for ( int j = 0 ; j < list.size() ; j++)
            std::cout << letter << j << ": " <<list[j] << '\n';
        std::cout << "Vector: " << vec << '\n';
        Orbit orb = orbit(list, vec);
        std::cout << "Orbit Size: " << orb.size() << '\n';
    }
    return 0;
}
