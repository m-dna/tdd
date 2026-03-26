#include <gtest/gtest.h>
#include "stick_cheoljun99/stick_cheoljun99.hpp"

class StickTest : public ::testing::Test {
protected:
    Stick stick;  // 공통으로 쓸 객체

    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(StickTest,resultFunc) {    
    EXPECT_EQ(stick.resultFunc(23), 4);
    EXPECT_EQ(stick.resultFunc(32), 1);
    EXPECT_EQ(stick.resultFunc(64), 1);
    EXPECT_EQ(stick.resultFunc(48), 2);
    EXPECT_THROW(stick.resultFunc(0), std::invalid_argument);
    EXPECT_THROW(stick.resultFunc(-1), std::invalid_argument);
}