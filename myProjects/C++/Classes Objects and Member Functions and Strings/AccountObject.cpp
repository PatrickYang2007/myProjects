

#include <iostream>
#include <string>
#include "Account.h"


using namespace std;

int main(){
    Account account1=Account("Jane Green", 50);
    cout<< "account1: "<<account1.getName()<<" your balance is: $"<<account1.getBalance()<<"\n";
   
    cout<<"Enter deposit amount for account1: ";
    int depositAmount;
    cin>>depositAmount;
    cout<<"adding "<< depositAmount<<" to you bank account";
    account1.deposit(depositAmount);
    cout<<"\nyour balance is now "<< account1.getBalance()<<" Congrats"<<"\n";
    
    cout<<"How much money would you like to widthdraw\n";
    int amountWidthdraw;
    cin>>amountWidthdraw;
    account1.widthdraw(amountWidthdraw);
    




}
