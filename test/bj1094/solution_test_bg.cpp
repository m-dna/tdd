#include <gtest/gtest.h>
#include "bj1094/solution_bg.hpp"

class SolutionTest_bg : public ::testing::Test {
protected:
    Solution_bg sol;  // 공통으로 쓸 객체

    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(SolutionTest_bg, input) {    
    EXPECT_EQ(sol.solve(23), 4);
    EXPECT_EQ(sol.solve(32), 1);
    EXPECT_EQ(sol.solve(64), 1);
    EXPECT_EQ(sol.solve(48), 2);
    EXPECT_EQ(sol.solve(1),1);
}