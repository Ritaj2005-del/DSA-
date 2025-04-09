#include<iostream>
using namespace std;

template <typename T>
void getInput(T arr[], T size) {

	cout << "Enter the elements of the array:" << endl;
	for (int i = 0; i < size; i++) {

		cin >> arr[i];
	}
}

template <typename T>
void SelectionSort(T arr[], T size) {

	for (int i = 0; i < size - 1; i++) {

		for (int j = i + 1; j < size; j++) {

			if (arr[j] < arr[i]) {

				T temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

}

template <typename T>
void PrintArray(T arr[], T size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

}

int main() {

	const int size = 5;
	int arr[size];

	getInput(arr, size);
	cout << "Before sorting:" << endl;
	PrintArray(arr, size);

	SelectionSort(arr, size);
	cout << endl;
	cout << "After sorting:" << endl;
	PrintArray(arr, size);

	return 0;
}