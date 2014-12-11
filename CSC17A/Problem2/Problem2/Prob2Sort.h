//
//  Prob2Sort.h
//  Problem2
//
//  Created by Juan on 12/9/14.
//  Copyright (c) 2014 Juan. All rights reserved.
//

#ifndef __Problem2__Prob2Sort__
#define __Problem2__Prob2Sort__

#include <iostream>
#include <algorithm>


template <class T>
void swap(T*, T*, bool);

template<class T>
void swapArray(T *, T *, int);

using namespace std;

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=NULL;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};

template<class T>
T * Prob2Sort<T>::sortArray(const T* array, int column, bool desc) {
    // copy the array into the index
    int nCol =15;
    int nRow = 10;
    
    if (column > nCol-1)
        column = 0;
    T *out = new T [nCol*nCol];
    for (int i = 0; i != 150; ++i) {
        out[i] = array[i];
    }
    
    for (int nLoops =0; nLoops != nRow; ++nLoops) {
        for (int i = 0; i != nRow-1; ++i) {
            if (desc){
                if (out[i*nCol+column] > out[(i+1)*nCol + column])
                    swap(out[i*nCol+column], out[(i+1)*nCol + column]);
            }
            else
                if (out[i*nCol+column] < out[(i+1)*nCol + column])
                    swap(out[i*nCol+column], out[(i+1)*nCol + column]);
        }
    }
    return out;
}

template<class T>
T * Prob2Sort<T>::sortArray(const T *array, int nRow, int nCol,
                            int column, bool desc) {
    T *out = new T [nRow*nCol];
    // copy the array
    for (int i = 0; i != nRow*nCol; ++i) {
        out[i] = array[i];
    }
    
    for (int nLoops =0; nLoops != nRow; ++nLoops) {
        for (int i = 0; i != nRow-1; ++i) {
            if (!desc){
                if (out[i*nCol+column] > out[(i+1)*nCol + column])
                    swapArray(out+i*nCol, out+(i+1)*nCol, nCol);
            }
            else
                if (out[i*nCol+column] < out[(i+1)*nCol + column])
                    swapArray(out+i*nCol, out+(i+1)*nCol, nCol);
        }
    }
    
    return out;
}

template<class T>
void swap(T *a, T *b) {
        T temp = *a;
        *a = *b;
        *b = temp;
}

template<class T>
void swapArray(T *a, T *b, int size) {
    T * temp = new T [size];
    copy(a, a+size, temp);  // copy into temp
    copy(b, b+size, a);     // overwrite a
    copy(temp, temp+size, b);
    
    delete []temp;
}

#endif /* defined(__Problem2__Prob2Sort__) */
