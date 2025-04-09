#include<iostream>
using namespace std;

template <class T>
int binarySearch(T arr[], int size, T key) {

	int low = 0;
	int high = size - 1;
	int mid = 0;

	while (low <= high) {

		mid = (low + high) / 2;
		if (arr[mid] == key) {
			cout << mid << endl;
			break;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}

		else
			low = mid + 1;
	}
	return -1;

}

int main() {


	const int size = 5;
	int arr[size];

	cout << "Enter array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int key;
	cout << "Enter the key you want to search:" << endl;
	cin >> key;

	binarySearch(arr, size, key);

	return 0;
}