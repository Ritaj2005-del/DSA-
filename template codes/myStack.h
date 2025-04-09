#pragma once
#include "Stack.h"

template <class T>
class myStack :public Stack<T> {

public:

	void push(T value);
	T pop();
	T top();
	bool isFull();
	bool isEmpty();
	myStack(int s);
	void Display();
	
};

template <class T>
bool myStack<T>::isFull() {

	return Stack<T>::currentSize == Stack<T>::maxSize;
}

template <class T>
bool myStack<T>::isEmpty() {

	return Stack<T>::currentSize == 0;
}

template <class T>
void myStack<T>::push(T value) {

	if (isFull()) {
		cout << "Stack is full.Cannot add values." << endl;
		return;
	}

	Stack<T>::arr[Stack<T>::currentSize] = value;
	Stack<T>::currentSize++;

}

template <class T>
T myStack<T>::pop() {

	if (isEmpty()) {
		cout << "Stack is empty." << endl;
		return T();
	}
	else {
		Stack<T>::currentSize--;
		return Stack<T>::arr[Stack<T>::currentSize];
	}
}

template <class T>
T myStack<T>::top() {

	if (isEmpty()) {
		cout << "Stack is empty." << endl;
		return NULL;
	}

	return Stack<T>::arr[Stack<T>::currentSize - 1];
}

template <class T>
myStack<T>::myStack(int s) :Stack<T>(s) {

}

template <class T>
void myStack<T>::Display()
{
	cout << "Max Size = " << Stack<T>::maxSize << endl;
	cout << "Current Size = " << Stack<T>::currentSize << endl;

	for (int i = 0; i < Stack<T>::currentSize; i++)
		cout << i << ". " << Stack<T>::arr[i] << endl;
}
