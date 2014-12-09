//
//  main.cpp
//  Problem2
//
//  Created by Juan on 12/9/14.
//  Copyright (c) 2014 Juan. All rights reserved.
//

#include <iostream>
#include "Prob2Sort.h"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char *test = new char [10];
    bool ascending = true;
    
    Prob2Sort<char> p2;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    if (infile.is_open()) cout << "Success\n";
    else cout << "Failed\n";
    
    char n = 143;
    cout << "N is: " << n<< endl;
    
    p2.sortArray(test, 5, ascending);
    
    return 0;
}
