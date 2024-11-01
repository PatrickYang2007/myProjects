#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
#include <random>

using namespace std;

int main(){
    default_random_engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1,6);

    

}