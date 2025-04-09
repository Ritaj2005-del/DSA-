#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {

	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
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

	cout<<linearSearch(arr, size, key);

	return 0;
}