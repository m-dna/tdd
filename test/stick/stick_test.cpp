#include <gtest/gtest.h>
#include "stick/stick.hpp"

vector<int> case1 = {0,0,0,0,0,0,1};
vector<int> case2 = {0,0,0,0,0,1,0};


class StickTest : public ::testing::Test {
protected:
    Stick st;  // 공통으로 쓸 객체

    void SetUp() override {
        // 필요하면 초기화
    }

    void TearDown() override {
        // 필요하면 정리
    }
};

TEST_F(StickTest, sum) {    
    EXPECT_EQ(st.sum(case1), 64);
    EXPECT_EQ(st.sum(case2), 32);
   
}

TEST_F(StickTest, cmp){
    EXPECT_EQ(st.cmp(st.sum(case1), 23), true);
    EXPECT_EQ(st.cmp(st.sum(case1), 64), true);

}

TEST_F(StickTest, find_minidx){
    EXPECT_EQ(st.find_minidx(case1), 6);
}

//TEST_P는 뭐임?

TEST_F(StickTest, divide2){
    vector<int> stic = case1;
    st.divide2(stic, st.find_minidx(stic), 23);

    EXPECT_EQ(st.sum(stic), 32);
}

TEST_F(StickTest, get_cnt){
    vector<int> stic = case1;
    st.divide2(stic, st.find_minidx(stic), 23);

    EXPECT_EQ(st.get_cnt(case1), 1);
    EXPECT_EQ(st.get_cnt(stic), 1);
    
}

TEST_F(StickTest, ans){
    EXPECT_EQ(st.ans(case1, 23), 4);
    EXPECT_EQ(st.ans(case1, 32), 1);
    EXPECT_EQ(st.ans(case1, 64), 1);
    EXPECT_EQ(st.ans(case1, 48), 2);
}

    