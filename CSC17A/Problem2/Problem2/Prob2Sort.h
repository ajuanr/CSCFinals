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

template<class T>
class Prob2Sort
{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=0;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};

template<class T>
T * Prob2Sort<T>::sortArray(const T *array, int col, bool desc) {
    int size = sizeof(array)/ sizeof(T);
    cout << "Size is: " << size << endl;
    
    T* out = new T[5];
    return out;
}

#endif /* defined(__Problem2__Prob2Sort__) */
