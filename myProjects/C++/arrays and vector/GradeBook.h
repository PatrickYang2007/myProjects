#include <string>
#include <iostream>
#include <iomanip>
#include <array>

class gradeBook{
    public:
    static const size_t students=10;

    gradeBook(const std::string& name, const std::array<int, students>&gradesArray):courseName(name), grades(gradesArray){
    }

    void setCourseName(const std::string& name){
        courseName=name;
    }

    const std::string& getCourseName() const{
        return courseName;
    }

    void displayMessage(){
        std::cout<<"Welcome to the grade book for \n"<<getCourseName()<<"!"<<std::endl;
    }

    void processGrades()const {
        outputGrades();

        std::cout<<std::setprecision(2)<<std::fixed;
        std::cout<<"\nClass average is " <<getAverage()<< std::endl;

        std::cout<<"Lowest grade is "<<getMinimum()<<" \nHighest grade is "<< getMaximum<<std::endl;

        outputBarChart();

    }

    int getMinimum()const{
        int lowGrade(100);

        for(int grade: grades){
            if(grade<lowGrade){
                lowGrade=grade;
            }
        }
        return lowGrade;
    }

    int getMaximum() const{
        int highGrade(0);

        for(int max: grades){
            if(max>highGrade){
                highGrade=max;
            }
        }
        return highGrade;
    }

    double getAverage() const{
        int total(0);

        for(int grade: grades){
            total+=grade;
        }
        return static_cast<double>(total)/grades.size();
    }

    void outputBarChart() const{
        std::cout<<"\nGrade distribution:" <<std::endl;

        const size_t frequencySize=11;
        std::array<unsigned int, frequencySize> frequency{};

        for(int grade: grades){
            ++frequency[grade/10];

        }

        for(size_t count=0; count<frequencySize; count++){
            if(count==0){
                std::cout<< " 0-9";
            }else if(count==10){
                std::cout<<" 100";
            }else{
                std::cout<<'*';

                std::cout<<std::endl;
            }
        }
    }

    void outputGrades()const{
        std::cout<<"]nThe grades are: \n\n";

        for(size_t student=0; student<grades.size(); student++ ){
            std::cout<<"Student"<< std::setw(2)<<student+1<<":"<<std::setw(3)<<grades[student]<<std::endl;
        }
    }

    
    private:
    std::string courseName;
    std::array<int, students> grades;
};