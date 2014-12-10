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
    int colSize = 15;
    int rowSize = 10;
    T *out = new T [colSize*rowSize];
    
    // copy the array
    for (int i = 0; i !=colSize*rowSize; ++i) {
        out[i] = array[i];
    }
    
    for ( int j = 0; j != 10; ++j) {
    for (int i = 0; i != 9; ++i) {
          cout << "Num: " << *(out+((i*colSize)+ col)) << " " << *(out+(((i+1)*colSize)+ col)) <<  endl;
        swap((out+(i*colSize)+ col), (out+((i+1)*colSize)+ col), !desc );
        cout << "swap: " << *(out+((i*colSize)+ col)) << " " << *(out+(((i+1)*colSize)+ col)) <<  endl;
//            T temp = *(out+(i*colSize)+ col);
//            *(out+(i*colSize)+ col) = *(out+(i*colSize)+ col+1);
//            *(out+(i*colSize)+ col+1) = temp;
        }
    }
    
    return out;
}

template<class T>
void swap(T *a, T *b, bool desc) {
    if ( a > b) {
        cout << "True\n";
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}



#endif /* defined(__Problem2__Prob2Sort__) */
