#include <string>

class Calculate{
public:
    Calculate(std::string name, int age){
        Name= name;
        Age=age;
    }
    std::string getName(){
        return Name;
    }

    int getMaxHeartRate(){
        maxHeartRate=220-Age;
        return maxHeartRate;
    }

    int returnAge(){
        return Age;
    }
private:
    int maxHeartRate;
    int Age;
    std::string Name;
};