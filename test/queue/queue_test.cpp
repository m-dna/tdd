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


TEST_F(QueueTest, throw_exception_when_empty) {
    // 큐가 비어있는 상태에서
    int_queue.clear();

    // 에러가 발생하는지 확인
    EXPECT_THROW(int_queue.pull(), std::underflow_error);
    EXPECT_THROW(int_queue.top(), std::underflow_error);
}


TEST_F(QueueTest, throw_exception_when_full) {
    // 큐를 가득 채움 (QUEUE_SIZE가 20이라고 가정)
    for(int i = 0; i < 30; i++) {
        int_queue.push(i);
    }

    for (int i = 10; i < 30; i++) {
        EXPECT_EQ(int_queue.pull(), i);
    }
    
}