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

using namespace std;
template <class T>
void swap(T*, T*, bool);

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
T * Prob2Sort<T>::sortArray(const T* array, int col, bool desc) {
    // copy the array into the index
    int colSize =16;
    int rowSize = 10;
    T *out = new T [rowSize*colSize];
    for (int i = 0; i != 150; ++i) {
        out[i] = array[i];
    }
    
    return out;
}

template<class T>
void swap(T *a, T *b, bool desc) {
    if ( a > b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}



#endif /* defined(__Problem2__Prob2Sort__) */
