#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Courses;

class Student
{
private:
    int studentId;
    string name, email;
    vector<Courses *> courseEnrolled;

public:
    Student()
    {
        cout << "Enter Student ID: ";
        cin >> studentId;
        cout << "Enter Student Name: ";
        getline(cin, name);
        cin.ignore();
        cout << "Enter Email Address: ";
        cin >> email;
    }

    void enrollCourse(Courses *course)
    {
        courseEnrolled.push_back(course);
    }

    void dropCourse(Courses *course)
    {
        courseEnrolled.erase(find(courseEnrolled.begin(), courseEnrolled.end(), course));
    }
    void viewCourse()
    {
        for (int i = 0; i < courseEnrolled.size(); i++)
        {
            cout << courseEnrolled[i]->getCourseName() << endl;
        }
    }
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
    Courses()
    {
        cout << "Enter Course Code: ";
        cin >> courseCode;
        cout << "Enter Course Name: ";
        getline(cin, courseName);
        cin.ignore();
    }

    void addStudent(Student *student)
    {
        this->student = student;
    }

    void removeStudent(Student *student)
    {
        if (this->student == student)
        {
            this->student = NULL;
        }
        else
        {
            cout << "Student not found" << endl;
        }
    }

    void viewStudent()
    {
        if (this->student == NULL)
        {
            cout << "No student enrolled" << endl;
        }
        else
        {
            cout << this->student->getName() << endl;
        }
    };
};

class Rooms
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