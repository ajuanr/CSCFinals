//
//  SavingsAccount.cpp
//  Problem4
//
//  Created by Juan Ruiz on 12/10/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(float init):FreqDeposit(0), FreqWithDraw(0) {
    (init > 0) ? Balance=init : Balance=0;
}

void SavingsAccount::Transaction(float amnt) {
    (amnt>=0) ? Deposit(amnt) : Withdraw(amnt);
}

float SavingsAccount::Withdraw(float amnt) {
    if (amnt*-1 > Balance)
        cout << "Error: Withdrawl exceeds balance\n";
    else
    Balance+=amnt;
    FreqWithDraw++;
    return FreqWithDraw;
}

float SavingsAccount::Deposit(float amnt) {
    Balance+= amnt;
    FreqDeposit++;
    return FreqDeposit;
}

void SavingsAccount::toString() {
    cout << "Balance=" << Balance << endl
        << "Withdrawal=" << FreqWithDraw << endl
    << "Deposit=" << fixed << setprecision(2) << FreqDeposit << endl;
}

float SavingsAccount::Total(float savint, int time) {
    return Balance*pow((1+savint),time);
}

float SavingsAccount::TotalRecursive(float savint, int time){
    Balance *= (1.0+savint);
    if ( time == 1)
        return Balance;
    else {
        return TotalRecursive(savint, time-1);
    }
}