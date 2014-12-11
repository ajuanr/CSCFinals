//
//  main.cpp
//  Final
//
//  Created by Juan Ruiz on 12/8/14.
//  Copyright (c) 2014 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

using namespace std;

void Menu();
int getN();
void def(int);
void Problem1();
void Problem2();
void Problem3();
void Problem4();
void Problem5();

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    Problem1();cout << endl;break;
            case 2:    Problem2();cout << endl;break;
            case 3:    Problem3();cout << endl;break;
            case 4:    Problem4();cout << endl;break;
            case 5:    Problem5();cout << endl;break;
            default:   def(inN);
        }
    } while(inN<6);
    
    return 0;
}

void Menu()
{
    cout<<"Type 1 for problem 2"<<endl;
    cout<<"Type 2 for problem 4"<<endl;
    cout<<"Type 3 for problem 10"<<endl;
    cout<<"Type 4 for problem 13"<<endl;
    cout<<"Type 5 for problem 15"<<endl;
    cout<<"Type 6 to exit \n"<<endl;
}
int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void Problem1() {
    cout << "Entering problem 1\n";
    char n=5;
    unsigned char rndseq[]={16,34,57,79,144};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    
        for (int i = 0; i != n; ++i) {
            cout << a.randFromSet() <<" ";
        }
        cout << endl;
    
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    cout << endl;
}

void Problem2() {
    cout << "Entering Problem 2\n";
    Prob2Sort<char> rc;
    bool ascending = true;
    
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    if (infile.is_open()) {cout << "Success\n";}
    else cout << "Failed\n";
    
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    int counter = 0;
    while(infile.get(*ch2)){
        cout<<*ch2;ch2++;
        if (++counter %15 == 0) cout << endl;
    }
    cout << endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10, 15, column,ascending);
    cout << endl;
    counter = 0;
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<15;j++)
        {
            cout<<zc[i*15+j];
        }
        cout << endl;
    }
    delete []zc;
    cout<<endl;
    
    infile.close();
    cout << endl;
}

void Problem3() {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    //Prob3Table<int> tab("Problem3.txt",rows,cols);
    
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols)+j]<<" ";
        }
        cout<<endl;
    }
}

void Problem4() {
    cout << "Entering Problem 4\n";
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
}

void Problem5() {
    cout << "Entering Problem 5\n";
    
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    
    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(60));
    Mary.toString();
    
}