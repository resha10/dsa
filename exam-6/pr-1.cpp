#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class MemoryCalculate 
{
private:

    T id;
    string name;

public:
   
    MemoryCalculate(T id, string name) : id(id), name(name) {
    }

     void display() const 
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    
    T getId() const 
        { 
        return id;
         }

    string getName() const 
    {
         return name;
     }
};

class StudentManagement
 {
private:

    vector< MemoryCalculate <int>> students; 

public:
   
    void addStudent(int id, string name) 
    {
        students.push_back(MemoryCalculate <int>(id, name));
        cout << "Student Added Successfully! \n";
    }

   
    void displayAllStudents()
     {
        if (students.empty()) 
        {
            cout << "No students available! \n";
            return;
        }
        cout << "Student List:\n";
        for (const auto &student : students) 
        {
            student.display();
        }
    }

    void removeStudent(int id) 
    {
        auto it = remove_if(students.begin(), students.end(), 
                            [id](const MemoryCalculate<int> &s) { return s.getId() == id; });

        if (it != students.end()) 
        {
            students.erase(it, students.end());
            cout << "Student with ID " << id << " removed successfully!\n";
        } 
        else 
        {
            cout << "Student with ID " << id << " not found!\n";
        }
    }

    void searchStudent(int id) 
    {
        for (const auto &student : students) 
        {
            if (student.getId() == id) 
            {

                cout << "Student Found:\n";
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }
};

int main()
 {
    StudentManagement StudManagment;
    int choice, id;
    string name;

    do 
    {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
         {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;

                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                StudManagment.addStudent(id, name);
                break;

            case 2:
                StudManagment.displayAllStudents();
                break;

            case 3:
                cout << "Enter Student ID to Remove: ";
                cin >> id;
                StudManagment.removeStudent(id);
                break;

            case 4:
                cout << "Enter Student ID to Search: ";
                cin >> id;
                StudManagment.searchStudent(id);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
