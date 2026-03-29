#include <gtest/gtest.h>
#include "bj1094/solution.hpp"

class SolutionTest : public ::testing::Test {
protected:
    Solution solution;  // 공통으로 쓸 객체

    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(SolutionTest, input1) {    
    EXPECT_EQ(solution.solve(23), 4);
}

TEST_F(SolutionTest, input2) {
    EXPECT_EQ(solution.solve(32), 1);
}

TEST_F(SolutionTest, input3) {
    EXPECT_EQ(solution.solve(64), 1);
}

TEST_F(SolutionTest, input4) {
    EXPECT_EQ(solution.solve(48), 2);
}