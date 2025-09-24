#include "employee.h"

ostream& operator << (ostream& out, employee& obj) {
	return out << obj.num << obj.name << obj.hours << endl;
}

istream& operator >> (istream& in, employee& obj) {
	cout << "Enter employee identification number: "; in >> obj.num;
	cout << "Enter employee's name: "; in >> obj.name;
	cout << "Enter number of hours worked: "; in >> obj.hours;
	return in;
}