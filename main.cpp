#include <iostream>
using namespace std;

class Student {  
public:
    string studentID;
    Student* nextStudent;

    Student(string studentID){  
        this->studentID = studentID;
        this->nextStudent = NULL;
    }
};

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

class UNICourseList {
    Courses* head;
    Courses* tail;
    Student* studHead;
    Student* studTail;

public:
    UNICourseList(){
        head = tail = NULL;
        studHead=studTail=NULL;
    }

    // * ADD NEW COURSES
    void addNewCourse(int coursesId) {
        Courses* newCourse = new Courses(coursesId);

        if (head == NULL) {
            head = tail = newCourse;
        } else {
            tail->nextCourse = newCourse;
            tail = newCourse;
        }
    }

    // * PRINT ALL COURSES

    void printAllCourses() {
        Courses* temp = head;

        while (temp != NULL) { // Fixed condition (was using head instead of temp)
            cout << temp->courseID << "->";
            temp = temp->nextCourse;
        }
        cout <<"NULL"<< endl;
    };

    // * Search For the course

    Courses* searchCourses(int courseId){
        Courses* temp=head;

        while(temp !=NULL){
            if(temp->courseID == courseId){
                // cout<<"Course Found : "<<temp;
                return temp;
            };
            temp=temp->nextCourse;
        };
        // cout<<"No Course Found";
        return NULL;
        
    }

    // * ADD NEW STUDENT IN COURSE

    void addNewStudent(string studentId , int courseId){
        Student* newStudent = new Student(studentId);
        if(searchCourses(courseId)){
           Courses* existingCourse = searchCourses(courseId);
            existingCourse->studentList=newStudent;
            
        if (studHead == NULL) {
            studHead = studTail = newStudent;
        } else{
            studTail->nextStudent=newStudent;
            studTail=newStudent;
        }
        }

    };

    // * PRINT ALL STUDENT

    void printStudent(int courseId){
        if(searchCourses(courseId)){
            Courses* exist = searchCourses(courseId);
            Student* allStudent = exist->studentList;
            Student* temp = studHead;
            if(allStudent == NULL){
                cout<<"No Student Yet";
                return;
            }else{
                while(temp != NULL){
                    cout<<temp->studentID<<"\n";

                    temp=temp->nextStudent;
                }
            }
        }else{
            cout<<"No Course Exist";
            return;
        }

    };

    // * DELETE COURSE

};

int main() {
    UNICourseList uniLL;

    uniLL.addNewCourse(351);
    uniLL.addNewCourse(352);
    uniLL.addNewCourse(353);  

    uniLL.printAllCourses();  

    uniLL.addNewStudent("B23110006007",351);
    uniLL.addNewStudent("B23110006008",351);

    // uniLL.printStudent(353);

    return 0;
}
