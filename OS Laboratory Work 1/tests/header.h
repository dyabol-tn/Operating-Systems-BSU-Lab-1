#pragma once
#include <gtest/gtest.h>
#include "../employee.h"

// Фикстура для параметризованных тестов конструктора
struct EmployeeConstructorTest
	: public ::testing::TestWithParam<std::tuple<int, const char*, double>> {
};
