//
//  Problem1.cpp
//  Final
//
//  Created by Juan Ruiz on 12/8/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include "Prob1Random.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

Prob1Random::Prob1Random(const char n, const unsigned char *set) {
    nset = n;
    
    
    this->set = new char[n];
    
    // copy the set into member variable
    for (int i = 0; i != nset; ++i)
        this->set[i] = set[i];
    
    numRand = 0;
    map<char, int> mapFreq;
    for (int i = 0; i != 10000; ++i) {
        ++numRand;
        mapFreq[randFromSet()]++;
    }
    
    // copy these values into frequence array
    int i = 0;
    freq = new int [nset];
    for (map<char,int>::const_iterator iter = mapFreq.begin();
         iter != mapFreq.end(); ++iter) {
        //cout << iter->second<< " ";
        freq[i] = iter->second;
        ++i;
    }
}

Prob1Random::~Prob1Random() {
    delete []set;
}


char Prob1Random::randFromSet() {
    return set[rand()%nset];
}

int * Prob1Random::getFreq() const {
    return freq;
}

char * Prob1Random::getSet() const{
    return set;
}

int Prob1Random::getNumRand() const {
    return numRand;
}