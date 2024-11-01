#include <iostream>
#include <array>

using namespace std;
const size_t rows(2);
const size_t columns(3);
void printArray(const array<array<int, columns>, rows>&);

int main(){
    //array<array<type,column size>, rows size> name of array={xyz};

    array<array<int, columns>, rows> array1={1,2,3,4,5,6};
    array<array<int, columns>, rows> array2={1,2,3,4,5};

    cout<<"Values in array1 by row are: "<< endl;
    printArray(array1);

    cout<<"\nValues in array2 by row are: "<< endl;
    printArray(array2);



    return 0;
}
void printArray(const array<array<int, columns>, rows>& a){
    for(auto const& row: a){
    //auto just allows the compiler to interpret the type, const doesn't allow the changing of a because it is passed by reference. 
    //this for loop says for all rows in the array a, so row 1,2 etc
        for(auto const& element:row){
    //every element element that is in the rows
            cout<< element<<' ';
        }
        cout<<endl;
    }
}
