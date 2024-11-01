#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main(){
    Student account1("Jane Green", 93);
   

    cout<<account1.getName()<<"'s average is "<<account1.getAverage()<<" and their letter grade is "<<account1.getLetterGrade()<<"\n";
}