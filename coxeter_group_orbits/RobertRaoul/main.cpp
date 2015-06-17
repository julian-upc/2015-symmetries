//
//  main.cpp
//  orbit_h
//
//  Created by Robert Loewe on 07.06.15.
//  Copyright (c) 2015 Robert Loewe. All rights reserved.
//


#include <iostream>
#include <sstream>
#include <string>
#include "orbit.h"

using namespace std;

string printVector(VectorType v){
    std::string output;
    for(int i = 0; i < v.size(); i++){
        std::ostringstream os;
        os << v[i];
        std::string str = os.str();
        output.append(str);
        output.append(" ");
    }
    return output;
}

int main(){
    
    
 
    VectorType v = {0., 0., 0., 0., 0., 0., 0., 0.};
    
    GeneratorList B2 = createMatrixE(8);
    for (int i = 0; i < B2.size(); i++){
        cout << printVector(B2[i]) << endl;
    }
    cout << B2.size() << endl;
    
    timestamp_t t0 = get_timestamp();
    
    Orbit solution = orbit(B2, v);
    
    timestamp_t t1 = get_timestamp();

    cout << "size: " << solution.size() << endl;
    cout << "time: " << (t1 - t0) / 1000000.0L << "secs" << endl;
    cout << "time: " << (t1 - t0) / 60000000.0L << "mins" << endl;
    
   // for(auto s : solution){
     //   cout << printVector(s) << endl;
   // }
    
    /*
     VectorType normal = { 16, -1, -0.5};
     VectorType v = {1, 2, 3};
     VectorType vector = reflection(normal, v);
     cout << printVector(vector) << endl;
     cout << printVector(reflection(normal, vector)) << endl;
     
     */
    return 0;
}


