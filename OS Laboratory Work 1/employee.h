#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct employee
{
	int num;	// идентификационный номер сотрудника
	char   name[10];	// имя сотрудника
	double hours;	// количество отработанных часов

    employee()
        : num(0), hours(0.0)
    {
        name[0] = '\0';
    }

    employee(int n, const char* nm, double h)
        : num(n), hours(h)
    {
        std::strncpy(name, nm, sizeof(name));
        name[sizeof(name) - 1] = '\0';
    }
};

ostream& operator << (ostream& out, employee& obj);
istream& operator >> (istream& in, employee& obj);


// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.