#include "myArray.h"

int main() {

	myArray obj(5);
	obj.addValue(-3);
	obj.addValue(35);
	obj.addValue(17);
	obj.addValue(1);

	cout << "Removed Value:" << obj.removeValue() << endl;
	obj.Display();

	return 0;
}