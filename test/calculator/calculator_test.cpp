#include <gtest/gtest.h>
#include "calculator/calculator.hpp"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;  // 공통으로 쓸 객체

    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(CalculatorTest, Add) {    
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(2, 4), 6);
}

TEST_F(CalculatorTest, Subtract) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(-1, -4), 3);
}

TEST_F(CalculatorTest, Multiply) {
    EXPECT_EQ(calc.multiply(4, 3), 12);
}

TEST_F(CalculatorTest, Divide) {
    EXPECT_DOUBLE_EQ(calc.divide(10, 4), 2.5);
}

TEST_F(CalculatorTest, DivideByZero) {
    EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}

TEST_F(CalculatorTest, Modulo) {
    EXPECT_EQ(calc.modulo(10, 3), 1);
}

TEST_F(CalculatorTest, ModuloDivideByZero) {
    EXPECT_THROW(calc.modulo(10, 0), std::invalid_argument);
}

TEST_F(CalculatorTest, Power) {
    EXPECT_EQ(calc.power(10, 0), 1);
    EXPECT_EQ(calc.power(10, 1), 10);
    EXPECT_EQ(calc.power(2, 10), 1024);
    EXPECT_EQ(calc.power(2, 11), 2048);
    EXPECT_EQ(calc.power(2, 12), 4096);
    EXPECT_EQ(calc.power(2, 32), 4294967296);
    //EXPECT_EQ(calc.power(2, 63), 9223372036854775808);
}