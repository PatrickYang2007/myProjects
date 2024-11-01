#include <iostream>
#include <string>

using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(0)));
    int card=2+rand()%12;
    cout<<card;
}