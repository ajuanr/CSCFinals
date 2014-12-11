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
    Prob2Sort<char> rc;
    bool ascending = true;

    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    if (infile.is_open()) {cout << "Success\n";}
    else cout << "Failed\n";

    char *ch2=new char[10*16];
    char *ch2p=ch2;
    int counter = 0;
    while(infile.get(*ch2)){
        cout<<*ch2;ch2++;
        if (++counter %15 == 0) cout << endl;
    }
    cout << endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,column,ascending);
    cout << endl;
    counter = 0;
    for (int i = 0; i != 150; ++i) {
        cout << zc[i];
        if (++counter %15 == 0) cout << endl;
    }
    cout << endl;
//
//    for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<16;j++)
//        {
//            cout<<zc[i*16+j];
//        }
//        cout << endl;
//    }
//    delete []zc;
//    cout<<endl;
//    
//    infile.close();
//    cout << endl;
    
    
    return 0;
}
