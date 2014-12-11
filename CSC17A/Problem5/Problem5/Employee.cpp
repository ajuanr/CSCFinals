//
//  Employee.cpp
//  Problem5
//
//  Created by Juan Ruiz on 12/10/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "Employee.h"
using namespace std;
Employee::Employee(char name[], char job[], float rate)
:HoursWorked(0), GrossPay(0), NetPay(0){
    int nullChar = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        MyName[i] = name[i];
        nullChar = i+1;
    }
    MyName[nullChar] = '\0';

    for (int i = 0; job[i] != '\0'; ++i) {
        JobTitle[i] = job[i];
        nullChar = i+1;
    }
    JobTitle[nullChar] = '\0';

    HourlyRate = rate;
}