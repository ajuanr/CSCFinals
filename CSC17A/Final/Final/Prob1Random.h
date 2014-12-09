//
//  Prob1Random.h
//  Final
//
//  Created by Juan Ruiz on 12/8/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#ifndef __Final__Prob1Random__
#define __Final__Prob1Random__

class Prob1Random
{
private:
    char *set;      //The set of numbers to draw random numbers from
    char  nset;     //The number of variables in the sequence
    int  *freq;     //Frequency of all the random numbers returned
    int   numRand;  //The total number of times the random number function is called
public:
    Prob1Random(const char,const char *);     //Constructor
    ~Prob1Random(void);                       //Destructor
    char randFromSet(void);                   //Returns a random number from the set
    int *getFreq(void) const;                 //Returns the frequency histogram
    char *getSet(void) const;                 //Returns the set used
    int getNumRand(void) const;               //Gets the number of times randFromSet has
    //been called
};

#endif /* defined(__Final__Prob1Random__) */
