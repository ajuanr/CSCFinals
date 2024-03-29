//
//  main.cpp
//  Problem4
//
//  Created by Juan Ruiz on 12/10/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SavingsAccount.h"

using namespace std;

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.TotalRecursive((float)(0.10),7)
    <<" Recursive Calculation "<<endl;
    
    return 0;
}
