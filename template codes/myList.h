#include "List.h"

template<class T>
class myList :public List<T> {

public:


	virtual void addElementAtFirstIndex(T value);

	virtual void addElementAtLastIndex(T value);

	virtual T removeElementFromEnd();

	virtual void removeElementFromStart();

	bool isFull();
	bool isEmpty();

	bool insertAt(int index, T value);
	bool search(T);

	myList(T* a = nullptr, int size = 0; int current = 0);
	myList(const myList& obj);
	virtual ~myList();
};

template <class T>
bool myList<T>::isFull() {

	return List<T>::currentSize == List<T>::maxSize;
}

template<class T>
bool myList<T>::isEmpty() {

	return List<T>::currentSize == 0;
}

template <class T>
void myList<T>::addElementAtFirstIndex(T value) {

	if (isFull()) {
		cout << "Array is full. Cannot insert value." << endl;
		return;
	}

	for (int i = List<T>::currentSize; i > 0; i--) {
		List<T>::arr[i] = List<T>::arr[i - 1];
	}
	
	List<T>::arr[0] = value;
	List<T>::currentSize++;
}

template <class T>
void myList<T>::addElementAtLastIndex(T value) {

	if (isFull()) {
		cout << "Array is full." << endl;
		return;
	}

	List<T>::arr[List<T>::currentSize] = value;
	List<T>::currentSize++;

}

template <class T>
T myList<T>::removeElementFromEnd() {

	if (isEmpty()) {
		cout << "Cannot remove element." << endl;
		return T();
	}

	List<T>::currentSize--;
	return List<T>::arr[List<T>::currentSize];
}

template <class T>
void myList<T>::removeElementFromStart() {
	if (isEmpty()) {
		cout << "Cannot remove element. List is empty." << endl;
		return;
	}

	for (int i = 0; i < List<T>::currentSize - 1; ++i) {
		List<T>::arr[i] = List<T>::arr[i + 1];
	}

	List<T>::currentSize--;
}

template <class T>
bool myList<T>::insertAt(int index, T value) {

	if (index<0 || index> List<T>::currentSize || isFull()) {
		cout << "Index out of bounds." << endl;
	}

	for (int i = List<T>::currentSize; i > index; i--) {
		List<T>::arr[i] = List<T>::arr[i - 1];
	}

	List<T>::arr[index] = value;
	List<T>::currentSize++:

	return true;
}
