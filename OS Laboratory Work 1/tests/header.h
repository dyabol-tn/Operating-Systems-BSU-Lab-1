#pragma once
#include <gtest/gtest.h>
#include "../employee.h"

// �������� ��� ����������������� ������ ������������
struct EmployeeConstructorTest
	: public ::testing::TestWithParam<std::tuple<int, const char*, double>> {
};
