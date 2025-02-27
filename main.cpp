#include <iostream>
using namespace std;

class Courses {
    public:
    int courseID;
    Courses* nextCourse;
    Student* studentList;

    Courses(int courseID){
        this->courseID = courseID;
        this->nextCourse = NULL;
        this->studentList = NULL;
    }
};

class Student {
    public:
    string studentID;
    Student* nextStudent;

    Student(int studentID){
        this->studentID = studentID;
        this->nextStudent = NULL;
    }
};

class UNICourseList{

};

int main(){

}