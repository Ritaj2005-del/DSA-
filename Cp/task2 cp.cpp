#include<iostream>
#include<string>
using namespace std;

class Employee {
public:
    string name;
    int ID;
    double salary;
};

class EmployeeSystem {
public:
    Employee employees[100];
    int count;

    EmployeeSystem() {
        count = 0;
    }

    void AddEmployee(string name, int ID, double salary) {
        employees[count].name = name;
        employees[count].ID = ID;
        employees[count].salary = salary;
        count++;
    }

    //using selection sort
    void SortEmployees() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (employees[i].salary > employees[j].salary) {
                    string tempName = employees[i].name;
                    employees[i].name = employees[j].name;
                    employees[j].name = tempName;

                    int temp = employees[i].ID;
                    employees[i].ID = employees[j].ID;
                    employees[j].ID = temp;

                    double tempSalary = employees[i].salary;
                    employees[i].salary = employees[j].salary;
                    employees[j].salary = tempSalary;
                }
            }
        }
    }

    void searchEmployee(double salary) {
        for (int i = 0; i < count; i++) {
            if (employees[i].salary == salary) {
                cout << "Name: " << employees[i].name << ", ID: " << employees[i].ID << ", Salary: " << employees[i].salary << endl;
                return;
            }
        }
        cout << "Employee not found." << endl;
    }

    void Display() {
        for (int i = 0; i < count; i++) {
            cout << "Name:" << employees[i].name << endl;
            cout << "ID:" << employees[i].ID << endl;
            cout << "Salary:" << employees[i].salary << endl;
        }
    }
};

int main() {
    EmployeeSystem system;

    while (true) {
        cout << "\n1. Add Employee" << endl;
        cout << "2. Sort Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int id;
            double salary;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter salary: ";
            cin >> salary;

            system.AddEmployee(name, id, salary);
            break;
        }
        case 2:
            system.SortEmployees();
            break;
        case 3: {
            double salary;
            cout << "Enter salary to search: ";
            cin >> salary;
            system.searchEmployee(salary);
            break;
        }
        case 4:
            system.Display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}