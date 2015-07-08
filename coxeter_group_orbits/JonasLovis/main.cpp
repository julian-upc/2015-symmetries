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

const static char letter = 'B';

int main(int argc, const char * argv[]) {
    for (int i =  8; i < 9; i++){
        VectorType vec (i);
        if ( letter != 'I' && letter != 'F' ){
            for ( int j = 0 ; j < i ; j++){
                vec[j] = (i*j+0.7)*pow(-1, j);
            }
        }else{
            if (letter == 'I')
                vec = {0.4231 , -17.33312 };
            else
                vec = {0.4231 , -17.33312 , 89.23 , -200.02};
        }
        GeneratorList list = simple_roots(letter, i);
        std::cout << "Generator Size: " << list.size() << '\n';
        for ( int j = 0 ; j < list.size() ; j++)
            std::cout << letter << j << ": " <<list[j] << '\n';
        std::cout << "Vector: " << vec << '\n';
        Orbit orb = orbit(list, vec);
        std::cout << "Orbit Size: " << orb.size() << '\n';
    }
    return 0;
}
