#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
struct Student
{
    int ID;
    Student* studentNext;
    string studentName;
};
struct Course
{
    int courseCode;
    struct Student* studentStart;
    string courseName;
    Course* courseNext;
}; struct Course *courseStart;

void insertCourse()
{
    int newCode;
    cout << "Enter Code of the course: ";
    cin >> newCode;
    
    Course *current = courseStart;
    while (current != NULL)
    {
        if (current->courseCode == 0)
        {
            cout << "It is an invalid code.\n";
            return;
        }
        else if (current->courseCode == newCode)
        {
            cout << "Following code already exists.\n";
            return;
        }
        current = current->courseNext;
    }
    cin.ignore();
    string courseName;
    cout << "Enter Name of the course: ";
    getline (cin, courseName);
    Course *temp = new Course;
    temp->courseCode = newCode;
    temp->courseName = courseName;
    temp->courseNext = NULL;
    temp->studentStart = NULL;

    if (courseStart == NULL)
    {
        courseStart = temp;
    }
    else
    {
        current = courseStart;
        while (current->courseNext != NULL)
        {
            current = current->courseNext;
        }
        current->courseNext = temp;
    }
}

void insertStudent()
{
    int ID;
    int courseID;
    string studentName;
    cout << "Enter ID of the student: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter Name of the student: ";
    getline (cin, studentName);
    cout << "Enter code of the course, student wants to enroll in: ";
    cin >> courseID;

    Course *courseCurrent = courseStart;
    
     while (courseCurrent != NULL)
        {
            if (courseCurrent->courseCode == courseID)
            {
                Student *studentCurrent = courseCurrent->studentStart;
                while (studentCurrent != NULL)
                {
                    if (studentCurrent->ID == ID)
                    {
                        cout << "Student is already enrolled in this course!\n";
                        return;
                    }
                    studentCurrent = studentCurrent->studentNext;
                }
                Student *temp = new Student;
                temp->ID = ID;
                temp->studentName = studentName;
                temp->studentNext = NULL;

                if (courseCurrent->studentStart == NULL)
                {
                    courseCurrent->studentStart = temp;
                }
                else
                {
                   studentCurrent = courseCurrent->studentStart;
                   while (studentCurrent->studentNext != NULL)
                   {
                       studentCurrent = studentCurrent->studentNext;
                   }
                   studentCurrent->studentNext = temp;
                }
                return;
            }
            courseCurrent = courseCurrent->courseNext;
        }
        cout << "Following course does not exist.\n";
}

void deleteStudentCourse()
{
    Course *courseCurrent = courseStart;
    int toDelete;
    int courseCode;
    cout << "Enter code of the course, student is enrolled in: ";
    cin >> courseCode;
    //Course check
    while (courseCurrent != NULL)
    {
        if(courseCode != courseCurrent->courseCode)
        {
            courseCurrent = courseCurrent->courseNext;
        }

        else 
        {
            break;
        }
    }
    if (courseCurrent == NULL)
        {
            cout << "Following course does not exist.\n";
            return;
        }
    cout << "Enter ID of the student to delete: ";
    cin >> toDelete;
    Student *studentCurrent = courseCurrent->studentStart;
    Student *studentPrevious = NULL;
    while (studentCurrent != NULL)
    {
        if (studentCurrent->ID == toDelete)
        {
            if (studentPrevious == NULL)
            {
            courseCurrent->studentStart = studentCurrent->studentNext;
            free(studentCurrent);
            }
            else
            {
                studentPrevious->studentNext = studentCurrent->studentNext;
            }
            free(studentCurrent);
            cout << "ID " << toDelete << " is deleted.\n";
            return;
        }
        studentPrevious = studentCurrent;
        studentCurrent = studentCurrent->studentNext;
    }
    cout << "Following student is not enrolled in this course.\n";
    return;   
}

void Print()
{
    if (courseStart == NULL)
    {
    cout << "No Courses!!\n";
    return;
    }
    Course *courseCurrent = courseStart;
    while (courseCurrent != NULL)
    {
        cout << "Course Name: " << courseCurrent->courseName << "\n";
        cout << "Course code: " << courseCurrent->courseCode << "\n";
        Student *studentCurrent = courseCurrent->studentStart;
        if (studentCurrent == NULL)
        {
            cout << "There are currently no students enrolled in this course.\n";
        }
        else if (studentCurrent != NULL) 
        {
            cout << "Students enrolled in the course are: \n";
        }
        while (studentCurrent != NULL)
        {
            cout << studentCurrent->ID << "\n";
            studentCurrent = studentCurrent->studentNext;
        }
        cout << "\n";
        courseCurrent = courseCurrent->courseNext;
    }
}

void search ()
{
    bool studentFound = false;
    cout << "Enter ID of the student to search: ";
    int toSearch;
    cin >> toSearch;
    Course *courseCurrent = courseStart;
    cout << "The student is enrolled in the following courses:\n";
    while(courseCurrent != NULL)
    {
        Student *studentCurrent = courseCurrent->studentStart;
        while (studentCurrent != NULL)
        {
            if (studentCurrent->ID == toSearch)
            {
                cout << courseCurrent->courseCode << "\n"; 
            }
            studentCurrent = studentCurrent->studentNext;
        }
        courseCurrent = courseCurrent->courseNext;
        studentCurrent = courseCurrent->studentStart;
    }
    return;
    if (studentFound == false)
    {
        cout << "Following student is not enrolled in any course.\n";
    }
}

void deleteStudent ()
{
    bool studentFound = false;
    cout << "Enter ID of the student to delete: ";
    int toDelete;
    cin >> toDelete;
    Course *courseCurrent = courseStart;
    while(courseCurrent != NULL)
    {
        Student *studentCurrent = courseCurrent->studentStart;
        Student *studentPrevious = NULL;
        while (studentCurrent != NULL)
        {
            if (studentCurrent->ID == toDelete)
            {
                if (studentPrevious == NULL)
                {
                    courseCurrent->studentStart = studentCurrent->studentNext;
                }
                else
                {
                    studentPrevious->studentNext = studentCurrent->studentNext;
                }
                free(studentCurrent);
                studentFound = true;
                break;
            }
            studentPrevious = studentCurrent;
            studentCurrent = studentCurrent->studentNext;
        }
        courseCurrent = courseCurrent->courseNext;
    }
    return;
    if (studentFound == false)
    {
        cout << "Following student is not enrolled in any course.\n";
    }
}

void deleteACourse()
{
    cout << "Enter code of the course you want to delete: ";
    int toDelete; 
    cin >> toDelete;
    struct Course *courseCurrent = courseStart;
    struct Student *studentCurrent = NULL;
    struct Course *prev = NULL;
    while (courseCurrent != NULL)
    {
    if (courseCurrent->courseCode == toDelete)
    {
        while (studentCurrent != NULL)
        {
            studentCurrent = courseCurrent->studentStart;
            struct Student *temp = studentCurrent;
            studentCurrent = studentCurrent->studentNext;
            free(temp);
        }
        if (prev == NULL)
        {
            courseStart = courseCurrent->courseNext;
        }
        else
        {
            prev->courseNext = courseCurrent->courseNext;
        }
        free (courseCurrent);
        cout << "Course " << toDelete << " is deleted.\n";
        return;
    }
    prev = courseCurrent;
    courseCurrent = courseCurrent->courseNext;
    }
    cout << "Following course does not exist.\n";
}

int main()
{
    int opt;
    cout << "\t 1: Enter a course. \n";
    cout << "\t 2: Enroll a student to a course. \n";
    cout << "\t 3: Delete a student from a course. \n";
    cout << "\t 4: Print. \n";
    cout << "\t 5: Search for a student. \n";
    cout << "\t 6: Delete a student from all courses. \n";
    cout << "\t 7: Delete a course. \n";
    cout << "\t 0: Exit. \n";
    cin >> opt;
    
    while (opt != 0)
    {
        if (opt == 1)
        {
            insertCourse();
        }
        if (opt == 2)
        {
            insertStudent();
        }
        if (opt == 3)
        {
            deleteStudentCourse();
        }
        if (opt == 4)
        {
            Print();
        }
        if (opt == 5)
        {
            search();
        }
        if (opt == 6)
        {
            deleteStudent();
        }
        if (opt == 7)
        {
            deleteACourse();
        }
        cout << "\t 1: Enter a course. \n";
        cout << "\t 2: Enroll a student to a course. \n";
        cout << "\t 3: Delete a student from a course. \n";
        cout << "\t 4: Print. \n";
        cout << "\t 5: Search for a student. \n";
        cout << "\t 6: Delete a student from all courses. \n";
        cout << "\t 7: Delete a course. \n";
        cout << "\t 0: Exit. \n";
        cin >> opt;
    }
    return 0;
}