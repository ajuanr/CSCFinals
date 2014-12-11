//
//  Prob3Table.h
//  Problem3
//
//  Created by Juan on 12/10/14.
//  Copyright (c) 2014 Juan. All rights reserved.
//

#ifndef Problem3_Prob3Table_h
#define Problem3_Prob3Table_h

#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Prob3Table
{
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char * file, int nRows, int nCols) {
    rows = nRows;
    cols = nCols;
    
    fstream inFile;
    inFile.open(file);
    if (!inFile.is_open()) cout << "File failed to open";
    
    table = new T [nRows*nCols];
    rowSum = new T [nRows];
    colSum = new T [nCols];
    
    int cSum = 0;       // column sum
    int rSum = 0;
    
    // fill the table
    for (int row = 0; row != nRows; ++row) {
        for (int col = 0; col != nCols; ++col) {
            inFile >> table[row*nCols + col];
        }
        cout << endl;
    }
    cout << endl;
    
    int currentColumn = 0;
    for (int row = 0; row != nRows; ++row) {
        for (int col = 0; col != nCols; ++col) {
            rSum += table[row*nCols + col];
            if (col != nCols-1)
                cSum += table[col*nCols + row];
        }
        rowSum[row] = rSum;
        colSum[currentColumn++] = cSum;
        rSum = 0;
        cSum = 0;
    }

}

#endif
