#include "employee.h"

int main(int argc, char* argv[]) {
	ifstream filein(argv[1], ios::binary);
	ofstream fileout(argv[2]);

	if (!filein.is_open()) {
		cout << "Binary file opening error!" << endl;
		return 1;
	}

	if (!fileout.is_open()) {
		cout << "Text file opening error!" << endl;
		return 1;
	}

	employee empl;
	int i = 1;
	int hourlyPay = stoi(argv[3]);

    fileout << "Отчет по файлу \"" << argv[1] << "\"\n";
    fileout << left << setw(5) << "№"
        << setw(20) << "Identification number"
        << setw(15) << "Name"
        << setw(10) << "Hours"
        << setw(15) << "Accrued salary"
        << "\n";

    while (filein.read(reinterpret_cast<char*>(&empl), sizeof(employee))) {
        double accruedSalary = empl.hours * hourlyPay;
        fileout << left << setw(5) << (to_string(i) + ".")
            << setw(20) << empl.num
            << setw(15) << empl.name
            << setw(10) << empl.hours
            << setw(15) << fixed << setprecision(2) << accruedSalary
            << "\n";
        i++;
	}
	return 0;
}