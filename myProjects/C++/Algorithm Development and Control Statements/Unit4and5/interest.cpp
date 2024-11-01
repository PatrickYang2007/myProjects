#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    cout<< fixed<<setprecision(2);

    double principal;
    double interestRate;
    cout<<"Enter the amount of money you want to invest and the interest rate you have: ";
    cin>>principal>>interestRate;

    cout<<"\nYour principal: "<<principal;
    cout<<"\nYour interest rate: " <<interestRate;

    cout<<"\nYear"<<setw(20)<< "Amount on deposit\n";
    
    for(int year=1; year<=10; year++){
        double amount= principal*pow(1.0 + interestRate, year);

        cout<<setw(4)<<year<<setw(20)<<amount<<endl;
    }
    
}