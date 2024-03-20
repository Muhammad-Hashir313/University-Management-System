#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    int studentId;
    string name, email;
    vector<Courses *> courseEnrolled;

public:
    void enrollCourse();
    void dropCourse();
    void viewCourse();
};

class Teacher
{
private:
    int teacherId;
    string name, email;
    vector<Courses *> courseTaught;

public:
    void assignCourse();
    void removeCourse();
    void viewCourse();
};

class Courses
{
private:
    int courseCode;
    string courseName;
    Teacher *teacher;
    Student *student;

public:
    void addStudent();
    void removeStudent();
    void viewStudent();
};

class Classes
{
private:
    string roomNumber;
    int roomCapacity;

public:
    void checkAvailability();
    void bookRoom();
};

int main()
{

    system("pause");
    return 0;
}