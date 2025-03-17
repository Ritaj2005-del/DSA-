#include<iostream>
using namespace std;

class Employee {

public:
	double salary;
	virtual double CalculateSalary() = 0;

};

class FullTime :public Employee {

public:

	const double salary = 1000;

	double CalculateSalary() override {
		cout << salary;
		return salary;
	}

};

class PartTime :public Employee {

public:

	double sal;
	
	PartTime(double sal) {
		salary = sal;
	}

	double CalculateSalary() override {
		cout << salary;
		return salary;
	}

};

int main() {

	cout << "The salary for Full Time employee is:" << endl;
	FullTime f1;
	f1.CalculateSalary();


	cout << endl;

	cout << "The salary for Part Time employee is:" << endl;
	PartTime p1(2000);
	p1.CalculateSalary();

	return 0;
}
