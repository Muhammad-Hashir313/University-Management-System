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
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
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

    string getName() const { return name; }
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
        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, courseName);
    }

    string getCourseName() const { return courseName; }

    void addStudent(Student *student)
    {
        this->student = student;
    }

    void removeStudent(Student *student)
    {
        if (this->student == student)
        {
            delete this->student;
            this->student = nullptr;
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



int main()
{

    system("pause");
    return 0;
}
