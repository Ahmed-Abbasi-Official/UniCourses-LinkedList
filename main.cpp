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
                // cout<<"Course Found : "<<temp->courseID;
                return temp;
            };
            temp=temp->nextCourse;
        };
        // cout<<"No Course Found";
        return NULL;
        
    }

    // * ADD NEW STUDENT IN COURSE

    void addNewStudent(string studentId, int courseId) {
        Student* newStudent = new Student(studentId);
        Courses* existingCourse = searchCourses(courseId);
    
        if (existingCourse) {
            if (existingCourse->studentList == NULL) {
                existingCourse->studentList = newStudent; // First student
            } else {
                Student* temp = existingCourse->studentList;
                while (temp->nextStudent != NULL) {
                    temp = temp->nextStudent;
                }
                temp->nextStudent = newStudent; // Append at the end
            }
        }
    }
    

    // * PRINT ALL STUDENT

    void printStudent(int courseId) {
        Courses* exist = searchCourses(courseId);
        if (!exist) {
            cout << "No Course Exist\n";
            return;
        }
    
        Student* temp = exist->studentList;
        if (!temp) {
            cout << "No Student Yet\n";
            return;
        }
    
        while (temp != NULL) {
            cout << temp->studentID << "\n";
            temp = temp->nextStudent;
        }
    }
    

    // * DELETE COURSE

    void deleteCourse(int courseId){
        if(searchCourses(courseId)){
            Courses* existCourse = searchCourses(courseId);
            Student* allStudent = existCourse->studentList;
            Student* temp  = studHead;
            Courses* tempC=head;
            while(temp != NULL){
                Student* prev = temp;
                temp->nextStudent=NULL;
                temp=temp->nextStudent;
                delete prev;
            }

            while(tempC->nextCourse->courseID != courseId){
                tempC = tempC->nextCourse;
            }

            Courses* prevC = tempC->nextCourse;

            tempC->nextCourse=tempC->nextCourse->nextCourse;

            prevC->nextCourse = NULL;
            delete prevC;

            return; 
        }else{
            cout<<"No Course Exist Recently";
            return;
        }
    }


    // * DELETE STUDENT FROM A COURSE
    void deleteStudentFromAllCourses(string studentId) {
        Courses* course = head; // Start from the first course
    
        while (course != NULL) {
            Student* curr = course->studentList;
            Student* prev = NULL;
    
            while (curr != NULL) {
                
                if (curr->studentID == studentId) {  
                    if (!prev) {  
                        course->studentList = curr->nextStudent; // Update course's head
                    } else {
                        prev->nextStudent = curr->nextStudent;  // Update linking
                    }
    
                    Student* temp = curr;
                    curr = curr->nextStudent;
                    delete temp;
                } else {
                    prev = curr;
                    curr = curr->nextStudent;
                }
            }
            course = course->nextCourse; 
        }
        cout << "Student " << studentId << " deleted from all courses!\n";
    }
    
    
    

};

int main() {
    UNICourseList uniLL;

    uniLL.addNewCourse(351);
    uniLL.addNewCourse(352);
    uniLL.addNewCourse(353);  

    

    uniLL.addNewStudent("B23110006007",351);
    uniLL.addNewStudent("B23110006008",351);

    uniLL.deleteStudentFromAllCourses("B23110006007");

    uniLL.printStudent(351);
    // uniLL.deleteCourse(352);
    uniLL.printAllCourses();  


    return 0;
}
