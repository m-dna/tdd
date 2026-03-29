#include <gtest/gtest.h>
#include <string>
#include "queue/queue.hpp"

using namespace std;

class QueueTest : public ::testing::Test {
protected:
    Queue<int> int_queue;
    Queue<string> string_queue;

    void SetUp() override {
        int_queue.clear();
    }

    void TearDown() override {
    }
};

TEST_F(QueueTest, push_and_top) {    
    // given
    int value = 3;
    int_queue.push(value);

    // when
    int top = int_queue.top();

    // then
    EXPECT_EQ(top, value);
}

TEST_F(QueueTest, push_and_pull) {    
    // given
    int v1 = 1;
    int v2 = 3;
    int_queue.push(v1);
    int_queue.push(v2);

    // when
    int_queue.pull();
    int second = int_queue.pull();

    // then
    EXPECT_EQ(second, v2);
}