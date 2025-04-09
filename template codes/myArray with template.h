#include "Array with template.h"

template <class T>
class myArray :public Array<T> {
public:

	void addValue(T value);
	T removeValue();
	bool isEmpty();
	bool isFull();
	myArray(int s);
	void Display();
};

template <class T>
myArray<T>::myArray(int s) :Array<T>(s) {


}

template <class T>
bool myArray<T>::isFull() {

	return Array<T>::currentSize == Array<T>::maxSize;
}

template <class T>
bool myArray<T>::isEmpty() {

	return Array<T>::currentSize == 0;

}


template <class T>
void myArray<T>::addValue(T value) {

	if (isFull()) {
		cout << "Array is full." << endl;
	}
	else {
		Array<T>::arr[Array<T>::currentSize] = value;
		Array<T>::currentSize++;
	}
}

template <class T>
T myArray<T>::removeValue() {

	if (isEmpty()) {
		cout << "Array is Empty. Cannot remove value." << endl;
		return NULL;
	}
	else {

		Array<T>::currentSize--;
		return Array<T>::arr[Array<T>::currentSize];
	}
}
template <class T>
void myArray<T>::Display() {

	cout << "Max Size:" << Array<T>::maxSize << endl;
	cout << "Current Size:" << Array<T>::currentSize << endl;

	for (int i = 0; i < Array<T>::currentSize; i++) {
	 cout << i << ". " << Array<T>::arr[i] << endl;
	}

}