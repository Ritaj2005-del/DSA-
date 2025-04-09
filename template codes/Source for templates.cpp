#include "myArray with template.h"

int main() {

	myArray<int> obj(5);

	obj.addValue(22);
	obj.addValue(-3);
	obj.addValue(12);
	obj.addValue(61);

	cout << "Removed value:" << obj.removeValue() << endl;

	obj.addValue(91);
	obj.addValue(0);
	obj.addValue(6);

	cout << "Int display" << endl;
	obj.Display();

	myArray<string> str(100);
	str.addValue("DSA");
	str.addValue("D6");
	str.addValue("Ritaj");

	cout << "String Display:" << endl;
	str.Display();

	return 0;
}