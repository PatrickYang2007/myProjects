#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    const size_t arraySize=7;
    array<string, arraySize> colors={"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

    //sorting
    cout<<"Unsorted array: "<< endl;

    for(string color: colors){
        cout<< color<< endl;
    }

    sort(colors.begin(), colors.end());

    cout<<"\n\nSorted array: "<< endl;
    
    for(string color: colors){
        cout<< color<< endl;
    }

    //searching

    bool found = binary_search(colors.begin(), colors.end(), "indigo");
    cout << "\n\nindigo" << " " << (found ? "was" : "was not") << " found in colors" << endl;


    return 0;
}