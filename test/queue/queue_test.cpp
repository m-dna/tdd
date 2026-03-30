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

TEST_F(QueueTest, size){
    int v1 = 1;
    int v2 = 2;
    int_queue.push(v1);
    int_queue.push(v2);

    EXPECT_EQ(int_queue.size(), 2);
    
}

TEST_F(QueueTest, push_in_fullqueue) {
    for (int i = 0; i < 20; i++) {
        int_queue.push(i);
    }

    int_queue.push(20);
    EXPECT_EQ(int_queue.top(), 1); 
}

TEST_F(QueueTest, pull_emptyQueue){
    EXPECT_THROW(int_queue.pull(), std::invalid_argument);
}

TEST_F(QueueTest, push_getSize){
    for(int i=0; i<QUEUE_SIZE; i++){
        int_queue.push(i);
    }
    
    int_queue.push(4);
    int_queue.push(5);

    EXPECT_EQ(int_queue.size(), 20);
}
