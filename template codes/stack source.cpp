#include "myStack.h"

int main() {

	myStack<int> obj(5);

	obj.push(265);
	obj.push(-3);
	obj.push(1985);

	cout << "Pop value:" << obj.pop() << endl;

	cout << "The top value is:" << obj.top() << endl;
	obj.Display();

	return 0;
}