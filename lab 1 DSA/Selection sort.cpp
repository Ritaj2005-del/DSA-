#include<iostream>
#include<string>
using namespace std;
int main() {
	int A[5] = { 2,6,8,5,6 };
	int smallsub;
	cout << "The Sorted Array Of The Elements : " << endl;
	for (int i = 0; i < 5 - 1; i++) {
		 smallsub = i;
		for (int j = i + i; j < 5 ; j++) {
			if (A[j] < A[smallsub]) {
				smallsub = j;
			}
		}
		swap(A[i], A[smallsub]);
	}
	cout << "The Sorted Array Become : ";
	for (int i = 0; i < 5; i++) {
		cout << A[i] << endl;
	}
}