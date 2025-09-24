#include "employee.h"

int main(int argc, char* argv[]) {
	ofstream fileout(argv[1], ios::binary);
	
	if (!fileout.is_open()) {
		cout << "File opening error!" << endl;
		return 1;
	}
	employee empl;
	for (int i = 0; i < stoi(argv[2]); i++) {
		cin >> empl;
		fileout.write(reinterpret_cast <char*>(&empl), sizeof(employee));
	}
	fileout.close();
	return 0;
}