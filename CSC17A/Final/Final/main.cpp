//
//  main.cpp
//  Final
//
//  Created by Juan Ruiz on 12/8/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "Prob1Random.h"

using namespace std;

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    char n=5;
    unsigned char rndseq[]={16,34,57,79,144};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
//    
//    for (int i = 0; i != n; ++i) {
//        cout << a.randFromSet() <<" ";//static_cast<int>(a.randFromSet()) << " ";
//        //cout << rndseq[i]+ 1 - 1 << endl;
//    }
//    cout << endl;
    
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    
    
        cout << endl;
    return 0;
}
