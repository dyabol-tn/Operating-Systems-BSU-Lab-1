// OS Laboratory Work 1.cpp.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

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
};

ostream& operator << (ostream& out, employee& obj);
istream& operator >> (istream& in, employee& obj);


// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
