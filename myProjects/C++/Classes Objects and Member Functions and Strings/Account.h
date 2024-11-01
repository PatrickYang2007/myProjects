#include <string>


class Account{
public:
    Account(std::string accountName, int initialBalance){
        name=accountName;
        if(initialBalance>0){
            balance=initialBalance;

        }
    }
    void deposit(int depositAmount){
        if(depositAmount>0){
            balance+=depositAmount;

        }
    }

    int getBalance() {
        return balance;
    }

    void widthdraw(int widthdrawAmount){
        if (widthdrawAmount>balance){
           std::cout<<"Unsuccesful, you do not have enough money\n";
        }else{
            balance= balance-widthdrawAmount;
            std::cout<<"Your new balance is: $"<< balance<<"\n";

        }
    }

    void setName(std::string accountName){
        name= accountName;
    }
    
    const std::string &getName(){
        return name;
    }
private:
    std:: string name;
    int balance=0;
};

