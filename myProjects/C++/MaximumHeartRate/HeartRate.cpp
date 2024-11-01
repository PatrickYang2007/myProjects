#include <iostream>
#include <string>
#include "Calculate.h"

using namespace std;


int main(){
    string name;
    int age;

    cout<<"What is your name?\n";
    getline(cin, name);

    cout<<"How old are you?\n";
    cin>>age;

    Calculate maxRateOfHeart(name, age);

    cout<<name<<" you are "<<age<<" due to this, your maximum heartrate is "<<maxRateOfHeart.getMaxHeartRate()<<" beats per minute\n";


}

