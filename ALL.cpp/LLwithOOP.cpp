#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    int ID;
    int marks;

public:
    Student(int id, int m)
    :ID(id), marks(m) {}

    int getID() const {
        return ID;
    }

    int getMarks() const {
        return marks;
    }
};

class StudentList {
private:
    vector<Student> students;

public:
    void insertStudent(int id, int marks) {
        for (const Student &student : students) {
            if (student.getID() == id) {
                cout << "ID " << id << " already exists in the list." << endl;
                return;
            }
        }
        students.emplace_back(id, marks);
    }

    void searchStudent(int id) {
        for (const Student &student : students) {
            if (student.getID() == id) {
                cout << "Marks of ID " << id << " are: " << student.getMarks() << endl;
                return;
            }
        }
        cout << "ID " << id << " not found in the list." << endl;
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == id) {
                students.erase(it);
                cout << "ID " << id << " has been deleted." << endl;
                return;
            }
        }
        cout << "ID " << id << " not found in the list." << endl;
    }

    void deleteAllStudents() {
        students.clear();
        cout << "All students have been deleted." << endl;
    }

    void printStudents() {
        if (students.empty()) {
            cout << "The list is empty." << endl;
            return;
        }

        cout << "\t\t The list of students is:" << endl;
        for (const Student &student : students) {
            cout << "ID: " << student.getID() << endl;
            cout << "Marks: " << student.getMarks() << endl;
        }
    }
};

int main() {
    StudentList studentList;

    while (true) {
        int option;
        cout << "\t 1: Insert an ID." << endl;
        cout << "\t 2: Search an ID." << endl;
        cout << "\t 3: Delete an ID." << endl;
        cout << "\t 4: Print the whole list." << endl;
        cout << "\t 5: Exit." << endl;
        cin >> option;
        switch (option) {
            case 1: {
                int id, marks;
                cout << "Enter ID of the student: ";
                cin >> id;
                cout << "Enter marks of the student: ";
                cin >> marks;
                studentList.insertStudent(id, marks);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of the student to search: ";
                cin >> id;
                studentList.searchStudent(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter ID of the student to delete: ";
                cin >> id;
                studentList.deleteStudent(id);
                break;
            }
            case 4:
                studentList.printStudents();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
