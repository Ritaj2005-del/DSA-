#include "Array.h"

class myArray :public Array {

public:

	void addValue(int value);
	int removeValue();
	myArray(int s);
	void Display();
};

myArray::myArray(int s):Array(s) {

}

void myArray::Display(){

	cout << "Max Size:" << maxSize << endl;
	cout << "Current Size:" << currentSize << endl;

	for (int i = 0; i < currentSize; i++) {

		cout << i << "." << arr[i] << endl;
	}
}

void myArray::addValue(int value) {

	arr[currentSize] = value;
	currentSize++;

}

int myArray::removeValue() {

	currentSize--;
	return arr[currentSize];
}