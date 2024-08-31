#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For exit()
using namespace std;

class Student {
private:
    int rollno, age;
    string name;

public:
    Student(int stdId, string stdName, int stdAge) : rollno(stdId), name(stdName), age(stdAge) {}

    void setRollno(int stdId) {
        rollno = stdId;
    }

    int getRollno() const {
        return rollno;
    }

    void setName(string stdName) {
        name = stdName;
    }

    string getName() const {
        return name;
    }

    void setAge(int stdAge) {
        age = stdAge;
    }

    int getAge() const {
        return age;
    }

    void displayStudent() const {
        cout << "Roll No : " << rollno << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

void updateStudent(vector<Student>& students) {
    string sname;
    bool found = false;
    int choice;

    cout << "\t\tEnter Name to Update Record : ";
    cin.ignore();
    getline(cin, sname);

    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getName() == sname) {
            found = true;
            cout << "\t\t---Student Found -----" << endl;
            cout << "\t\t 1. Update Rollno " << endl;
            cout << "\t\t 2. Update Name " << endl;
            cout << "\t\t 3. Update Age " << endl;
            cout << "\t\tEnter Your Choice : ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int rno;
                    cout << "\t\tEnter New Rollno : ";
                    cin >> rno;
                    students[i].setRollno(rno);
                    break;
                }
                case 2: {
                    string name;
                    cout << "\t\tEnter New Name : ";
                    cin.ignore();
                    getline(cin, name);
                    students[i].setName(name);
                    break;
                }
                case 3: {
                    int age;
                    cout << "\t\tEnter New Age : ";
                    cin >> age;
                    students[i].setAge(age);
                    break;
                }
                default:
                    cout << "\t\tInvalid Number" << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "\t\tRecord Not Found" << endl;
    }
}

void SearchStudent(const vector<Student>& students) {
    int rollno;
    cout << "\t\tEnter Rollno : ";
    cin >> rollno;

    for (const auto& student : students) {
        if (student.getRollno() == rollno) {
            cout << "\t\t--------Student Found ------------" << endl;
            student.displayStudent();
            return;
        }
    }
    cout << "\t\tStudent Not Found" << endl;
}

void DisplayAllStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\t\t No Student Found " << endl;
        return;
    }
    for (const auto& student : students) {
        student.displayStudent();
        cout << endl;
    }
}

void addNewStudent(vector<Student>& students) {
    int rollno, age;
    string name;

    cout << "Enter Rollno : ";
    cin >> rollno;

    for (const auto& student : students) {
        if (student.getRollno() == rollno) {
            cout << "\t\tStudent Already Exists" << endl;
            return;
        }
    }

    cout << "Enter Name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age : ";
    cin >> age;

    Student newStudent(rollno, name, age);
    students.push_back(newStudent);
}

void deleteStudent(vector<Student>& students) {
    string name;
    cout << "Enter Name to Delete : ";
    cin.ignore();
    getline(cin, name);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getName() == name) {
            students.erase(it);
            cout << "\t\tStudent Removed Successfully" << endl;
            return;
        }
    }
    cout << "\t\tStudent Not Found" << endl;
}

int main() {
    vector<Student> students;
    students.push_back(Student(1, "ali", 35));

    char choice;
    do {
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            cout << "\033[2J\033[1;1H";
        #endif

        int op;
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t** Student Management System **";
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t 1. Add New Student" << endl;
        cout << "\t\t 2. Display All Student " << endl;
        cout << "\t\t 3. Search Student" << endl;
        cout << "\t\t 4. Update Student" << endl;
        cout << "\t\t 5. Delete Student " << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << "\t\t Enter Your Choice : ";
        cin >> op;

        switch (op) {
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                return 0;
            default:
                cout << "\t\tInvalid Number " << endl;
        }

        cout << "\t\tDo You Want to Continue [Yes/No] ? : ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
