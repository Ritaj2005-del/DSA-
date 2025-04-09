#pragma once
#include<iostream>
using namespace std;

class Array {

protected:

	int* arr;
	int maxSize;
	int currentSize;

public:

	Array(int size);
	virtual void addValue(int value) = 0;
	virtual int removeValue() = 0;

};

Array::Array(int size) {

	maxSize = size;
	currentSize = 0;
	arr = new int[size];

}
