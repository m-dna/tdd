#include <gtest/gtest.h>
#include "bj1094/stick.hpp"

using namespace std;

class SolutionTest : public ::testing::Test {
protected:
    Stick sut;  // 공통으로 쓸 객체
    vector<int> case1 = {0,0,0,0,0,0,1};
    vector<int> case2 = {0,0,0,0,0,1,0};


    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(SolutionTest, sum) {    
    EXPECT_EQ(sut.sum(case1), 64);
    EXPECT_EQ(sut.sum(case2), 32);
   
}

TEST_F(SolutionTest, cmp){
    EXPECT_EQ(sut.cmp(sut.sum(case1), 23), true);
    EXPECT_EQ(sut.cmp(sut.sum(case1), 64), true);

}

TEST_F(SolutionTest, find_minidx){
    EXPECT_EQ(sut.find_minidx(case1), 6);
}

TEST_F(SolutionTest, divide2){
    vector<int> stic = case1;
    sut.divide2(stic, sut.find_minidx(stic), 23);

    EXPECT_EQ(sut.sum(stic), 32);
}

TEST_F(SolutionTest, get_cnt){
    vector<int> stic = case1;
    sut.divide2(stic, sut.find_minidx(stic), 23);

    EXPECT_EQ(sut.get_cnt(case1), 1);
    EXPECT_EQ(sut.get_cnt(stic), 1);
    
}

TEST_F(SolutionTest, ans){
    EXPECT_EQ(sut.ans(case1, 23), 4);
    EXPECT_EQ(sut.ans(case1, 32), 1);
    EXPECT_EQ(sut.ans(case1, 64), 1);
    EXPECT_EQ(sut.ans(case1, 48), 2);
}
