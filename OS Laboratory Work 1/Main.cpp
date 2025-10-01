#include "employee.h"

int main() {
	string binFile;
	int count;

	cout << "Enter the name of the binary file: ";
	cin >> binFile;

	cout << "Enter the number of records: ";
	cin >> count;

	string creatorCmd = "Creator.exe " + binFile + " " + to_string(count);

	STARTUPINFO si1{};
	PROCESS_INFORMATION pi1{};
	si1.cb = sizeof(si1);

	char cmdLine1[512];
	strcpy_s(cmdLine1, sizeof(cmdLine1), creatorCmd.c_str());

	if (!CreateProcess(NULL, cmdLine1, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1)) {
		cerr << "Error launching Creator" << endl;
		return 1;
	}

	WaitForSingleObject(pi1.hProcess, INFINITE);
	CloseHandle(pi1.hThread);
	CloseHandle(pi1.hProcess);

	ifstream fin(binFile, ios::binary);
	if (!fin.is_open()) {
		cerr << "Failed to open binary file: " << binFile << endl;
		return 1;
	}

	cout << "\nContents of the binary file:\n";
	employee emp{};
	while (fin.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
		cout << emp.num << " " << emp.name << " " << emp.hours << endl;
	}
	fin.close();

	string reportFile;
	double hourlyRate;

	cout << "\nEnter the name of the report file: ";
	cin >> reportFile;

	cout << "Enter the hourly pay rate: ";
	cin >> hourlyRate;

	string reporterCmd = "Reporter.exe " + binFile + " " + reportFile + " " + to_string(hourlyRate);

	STARTUPINFO si2{};
	PROCESS_INFORMATION pi2{};
	si2.cb = sizeof(si2);

	char cmdLine2[512];
	strcpy_s(cmdLine2, sizeof(cmdLine2), reporterCmd.c_str());

	if (!CreateProcess(NULL, cmdLine2, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2)) {
		cerr << "Error launching Reporter" << endl;
		return 1;
	}

	WaitForSingleObject(pi2.hProcess, INFINITE);
	CloseHandle(pi2.hThread);
	CloseHandle(pi2.hProcess);

	ifstream fout(reportFile);
	if (!fout.is_open()) {
		cerr << "Failed to open report file: " << reportFile << endl;
		return 1;
	}

	cout << "\nContents of the report:\n";
	string line;
	while (getline(fout, line)) {
		cout << line << endl;
	}
	fout.close();

	cout << "\nProgram finished." << endl;
	return 0;
}