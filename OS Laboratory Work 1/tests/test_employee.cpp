#include "header.h"
#include <sstream>

INSTANTIATE_TEST_SUITE_P(
    VariousInputs,
    EmployeeConstructorTest,
    ::testing::Values(
        std::make_tuple(1, "Anton", 10.5),
        std::make_tuple(2, "Sergey", 0.0),
        std::make_tuple(3, "Max", 99.9),
        std::make_tuple(4, "", 5.0),
        std::make_tuple(5, "LongName", 12.3)
    )
);

// Инициализация параметризованного
TEST_P(EmployeeConstructorTest, InitializesCorrectly) {
    int    expected_num = std::get<0>(GetParam());
    const char* expected_name = std::get<1>(GetParam());
    double expected_hours = std::get<2>(GetParam());

    employee e(expected_num, expected_name, expected_hours);

    EXPECT_EQ(e.num, expected_num);
    EXPECT_DOUBLE_EQ(e.hours, expected_hours);
    EXPECT_STREQ(e.name, expected_name);
}

// Конструктор по умолчанию
TEST(EmployeeAdditional, DefaultConstructor) {
    employee e;
    EXPECT_EQ(e.num, 0);
    EXPECT_DOUBLE_EQ(e.hours, 0.0);
    EXPECT_STREQ(e.name, "");
}

// Оператор вывода в поток
TEST(EmployeeIO, OutputOperator) {
    employee e(7, "Test", 8.75);
    std::ostringstream oss;
    oss << e;
    EXPECT_EQ(oss.str(), "7Test8.75\n");
}

// Оператор ввода из потока
TEST(EmployeeIO, InputOperator) {
    std::istringstream iss("9 Name 4.5");

    std::ostringstream nullout;
    auto* old_buf = std::cout.rdbuf(nullout.rdbuf());

    employee e;
    iss >> e;

    std::cout.rdbuf(old_buf);

    EXPECT_EQ(e.num, 9);
    EXPECT_DOUBLE_EQ(e.hours, 4.5);
    EXPECT_STREQ(e.name, "Name");
}
