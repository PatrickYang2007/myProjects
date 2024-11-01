#include <iomanip>
#include <iostream>
#include <string>
#include "DollarAmount.h"
using namespace std;

int main() {
    int a,b,c;
    cin>>a,b,c;

    
    DollarAmount d1(a);
    DollarAmount d2(b);

    cout << "After adding d2(" << d2.toString() << ") into d1(" << d1.toString() << "), d1=";
    d1.add(d2);
    cout << d1.toString() << "\n";

    cout << "After subtracting d2(" << d2.toString() << ") from d1(" << d1.toString() << "), d1=";
    d1.subtract(d2);
    cout << d1.toString() << "\n";

    cout << "After subtracting d1(" << d1.toString() << ") from d2(" << d2.toString() << "), d1=";
    d2.subtract(d1);
    cout << d2.toString() << "\n\n";

    cout << "Enter an integer interest rate and divisor. For example: \n"
        << "For 2%, enter: 2 100\n"
        << "For 2.3%, enter: 23 1000\n"
        << "For 2.37%, enter: 237 1000\n"
        << "For 2.375%, enter: 2375 100000\n";
    int rate;
    int divisor;
    cin >> rate >> divisor;
    DollarAmount balance(c);
    cout << "\nInitial balance: " << balance.toString() << endl;

    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    for (int year = 1; year <= 10; year++) {
        balance.addInterest(rate, divisor);
        cout << setw(4) << year << setw(20) << balance.toString() << endl;
    }

    return 0;
}
