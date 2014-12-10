//
//  main.cpp
//  Problem3
//
//  Created by Juan on 12/10/14.
//  Copyright (c) 2014 Juan. All rights reserved.
//

#include <iostream>
#include "Prob3TableInherited.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3Table<int> tab("Problem3.txt",rows,cols);
//    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
//    const int *naugT=tab.getTable();
//    for(int i=0;i<rows;i++)
//    {
//        for(int j=0;j<cols;j++)
//        {
//            cout<<naugT[i*cols+j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    const int *augT=tab.getAugTable();
//    for(int i=0;i<=rows;i++)
//    {
//        for(int j=0;j<=cols;j++)
//        {
//            cout<<augT[i*(cols+1)+j]<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}
