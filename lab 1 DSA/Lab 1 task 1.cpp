#include<iostream>
using namespace std;

class Shape {

public:
	double area = 0.0;

	virtual double Area() = 0;

};

class Circle:public Shape {

private:

	double radius;
public:

	const double pi = 3.14;

	Circle() {
		radius = 0.0;
	}

	Circle(double r) {
		radius = r;
	}


	double Area() override {
		area = pi * radius * radius;
		cout << area << endl;
		return area;
	}

};

class Rectangle:public Shape {

private:
	double length;
	double width;

public:

	Rectangle() {
		length = 0.0;
		width = 0.0;
	}

	Rectangle(double l, double w) {

		length = l;
		width = w;
	}

	double Area() override {
		area = length * width;
		cout << area << endl;
		return area;
	}

};

int main() {

	cout << "The area of circle is:" << endl;
	Circle c1(3.2);
	c1.Area();

	cout << "The area of rectangle is:" << endl;
	Rectangle r1(20.1, 2.2);
	r1.Area();


	return 0;
}