#include <iostream>
#include <string>

using namespace std;

class Printer{
  string _name;
  int _availablePaper;
  public:
    Printer(string name, int paper){
        _name=name;
        _availablePaper=paper;
    }
    void Print(string txtDoc){
        cout<<"Printing... "<<txtDoc<<"\n";

    }
};
int main(){
    Printer myPrinter("HP DeskJet 1234", 10);
    myPrinter.Print("My name is Patrick");
    return 0;
}

