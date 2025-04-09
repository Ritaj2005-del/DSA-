#pragma once
#include<iostream>
#include<string>
using namespace std;

template <class T>
class Array {
protected:
	T* arr;
	int maxSize;
	int currentSize;

public:

	Array(int size);
	virtual void addValue(T value) = 0;
	virtual T removeValue() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;

};

template <class T>
Array<T>::Array(int size) {

	maxSize = size;
	currentSize = 0;
	arr = new T[size];

}