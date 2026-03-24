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
}

TEST_F(CalculatorTest, Subtract) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

TEST_F(CalculatorTest, Multiply) {
    EXPECT_EQ(calc.multiply(4, 3), 12);
}

TEST_F(CalculatorTest, Divide) {
    EXPECT_DOUBLE_EQ(calc.divide(10, 2), 5.0);
}

TEST_F(CalculatorTest, DivideByZero) {
    EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}