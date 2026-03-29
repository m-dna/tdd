#include <gtest/gtest.h>
#include <string>
#include "queue/queue.hpp"

using namespace std;

class QueueTest : public ::testing::Test {
protected:
    Queue<int> int_queue;

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

TEST_F(QueueTest, size) {    
    // given
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    // when
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 3);
}

TEST_F(QueueTest, clear) {    
    // given
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    // when
    int_queue.clear();
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 0);
}

TEST_F(QueueTest, empty_pull) {    
    EXPECT_THROW(int_queue.pull(), std::runtime_error);
}

TEST_F(QueueTest, empty_top) {    
    EXPECT_THROW(int_queue.top(), std::runtime_error);
}

TEST_F(QueueTest, full_push) {    
    // given
    for (int i = 0; i < QUEUE_SIZE - 1; i++) {
        int_queue.push(i);
    }

    // then
    EXPECT_THROW(int_queue.push(QUEUE_SIZE), std::runtime_error);
}   