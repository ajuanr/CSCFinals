//
//  Employee.cpp
//  Problem5
//
//  Created by Juan Ruiz on 12/10/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <iomanip>
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

    HourlyRate = setHourlyRate(rate);
}

int  Employee::setHoursWorked(int hours) {
    if (hours >0 && hours < 84 ) {
        HoursWorked = hours;
        return HoursWorked;
    }
    cout << "Unacceptable hours worked\n";
    return HoursWorked;
}
float Employee::setHourlyRate(float rate) {
    if (rate > 0 && rate < 200) {
        HourlyRate = rate;
        return HourlyRate;
    }
    cout << "Unacceptable hourly rate\n";
    return HourlyRate;
}

void Employee::toString() {
    cout << "Name = " << MyName << " Job Title= " << JobTitle << endl
         << "Hourly rate = " << fixed << setprecision(0) << HourlyRate
         << " hours worked = " << HoursWorked
    << " Gross Pay= " << GrossPay << " Net Pay= " << NetPay << endl;
}

float Employee::getGrossPay(float rate, int hours) {
    //cout << "RATE*HOURS" << rate * hours << endl;
    float totalPay = 0;
    if (hours > 50) {
        float newRate = rate * 2;
        int hoursOvr = hours-50;
        totalPay += (newRate * hoursOvr);
        hours -= hoursOvr;
    }
    if (hours > 40) {
        float newRate = rate * 1.5;
        int hoursOvr = hours - 40;
        totalPay += (newRate * hoursOvr);
        hours -= hoursOvr;
        
        }
    totalPay+= (rate * hours);
    GrossPay = totalPay;
    
    return GrossPay;
}

double Employee::Tax(float pay) {
    float tax = 0;
    if ( pay > 1000) {
        float taxable = pay - 1000;
        pay -= taxable;
        tax+= taxable * .3;
    }
    if ( pay > 500) {
        float taxable = pay - 500;
        tax+= taxable * .2;
        pay -= taxable;
    }
    tax += pay *.1;
    return tax;
    
}

float Employee::getNetPay(float pay) {
    NetPay = getGrossPay(HourlyRate, HoursWorked) - Tax(pay);
    return NetPay;
}

float Employee::CalculatePay(float rate, int hours) {
    return getNetPay(getGrossPay(setHourlyRate(rate), setHoursWorked(hours)));
}