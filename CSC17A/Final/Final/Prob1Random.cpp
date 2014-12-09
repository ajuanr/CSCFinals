//
//  Problem1.cpp
//  Final
//
//  Created by Juan Ruiz on 12/8/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include "Prob1Random.h"
#include <sstream>
#include <iostream>

using namespace std;

Prob1Random::Prob1Random(const char n, const char *set) {
    stringstream charN;
    charN << n;
    
    nset = n;
    
    
    this->set = new char[nset-48];
    
    // copy the set into member variable
    for (int i = 0; i != nset-48; ++i) {
        this->set[i] = set[i];
        cout << this->set[i];
    }
}