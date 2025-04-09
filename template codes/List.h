#pragma once
#include<iostream>
using namespace std;

template <class T>
class List {

protected:
	T* arr;
	int maxSize;
	int currentSize;

public:

	List(T* a=nullptr, int size = 0, int current = 0);

	List(const List<T>& other);

	virtual ~List();

	virtual void addElementAtFirstIndex(T) = 0;
	
	virtual void addElementAtLastIndex(T) = 0;
	
	virtual T removeElementFromEnd() = 0;
	
    virtual void removeElementFromStart() = 0;
};

template <class T>
List<T>::List(T* arr, int size, int current) {

	maxSize = size;
	currentSize = current;

	arr = new T[maxSize];
	for (int i = 0; i < maxSize; i++) {
		arr[i] = a[i];
	}
}

template<class T>
List<T>::List(const List<T>& obj) {

	maxSize = obj.maxSize;
	currentSize = obj.currentSize;

	arr = new T[maxSize];
	for (int i = 0; i < maxSize; i++) {
		arr[i] = a[i];
	}
}

template <class T>
List<T>::~List() {

	delete[] arr;
}