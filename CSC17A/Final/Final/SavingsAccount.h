//
//  SavingsAccount.h
//  Problem4
//
//  Created by Juan Ruiz on 12/10/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#ifndef __Problem4__SavingsAccount__
#define __Problem4__SavingsAccount__

class SavingsAccount{
public:
    SavingsAccount(float);               //Constructor
    void  Transaction(float);            //Procedure
    float Total(float=0,int=0);	         //Savings Procedure
    float TotalRecursive(float=0,int=0);
    void  toString();                    //Output Properties
private:
    float Withdraw(float);               //Utility Procedure
    float Deposit(float);                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property
};


#endif /* defined(__Problem4__SavingsAccount__) */

