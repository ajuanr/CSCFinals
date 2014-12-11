//
//  Prob3TableInherited.h
//  Problem3
//
//  Created by Juan on 12/10/14.
//  Copyright (c) 2014 Juan. All rights reserved.
//

#ifndef Problem3_Prob3TableInherited_h
#define Problem3_Prob3TableInherited_h

#include "Prob3Table.h"

using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char *,int,int);          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;};
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file, int nRows, int nCols)
:Prob3Table<T>(file, nRows, nCols) {
    augTable = new T[(nRows+1)*(nCols+1)];
    
    for (int i = 0; i != nRows+1; ++i) {
        for (int j = 0; j != nCols; ++j) {
            if ( i == nRows ) {
                augTable[i*nCols+j] = this->rowSum[i];
            }
            else
                augTable[i*nCols + j] = this->table[i*nCols + j];
            cout <<augTable[i*nCols + j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i != nCols; ++i) {
        augTable[(nRows+1)*nCols + i] = this->colSum[i];
       // cout << augTable[(nRows+1)*nCols + i] << " ";
    }
    cout << endl;
    
//    for (int i = 0; i != nRows; ++i) {
//        augTable[i*nCols + nCols] = this->rowSum[i];
//        cout << augTable[i*nCols + nCols] << " ";
//    }
    cout << endl;
}

#endif
