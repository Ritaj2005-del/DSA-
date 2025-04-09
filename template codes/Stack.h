#pragma once
#include<iostream>
using namespace std;

template <class T>
class Stack {

protected:

	T* arr;
	int maxSize;
	int currentSize;

public:

	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() = 0;
	bool isFull();
	bool isEmpty();
	Stack(int size);
	virtual ~Stack();

};

template <class T>
Stack<T>::Stack(int size) {

	maxSize = size;
	currentSize = 0;
	arr = new T[size];

}
template <class T>
Stack<T>::~Stack() {

	delete[] arr;
}
