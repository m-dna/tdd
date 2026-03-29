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

TEST_F(QueueTest, full_push){
    // given
    for(int i=0;i<19;i++){
        int_queue.push(i);
    }
    // when
    EXPECT_EQ(int_queue.size(), 19);
    // then
    EXPECT_THROW(int_queue.push(1),std::overflow_error);
}

TEST_F(QueueTest, empty_pull) {    
    // given
    // when
    // then
    EXPECT_THROW(int_queue.pull(),std::underflow_error);
}

TEST_F(QueueTest, push_and_size){
    // given
    int v1 = 1;
    int v2 = 3;
    int_queue.push(v1);
    int_queue.push(v2);

    // when
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 2);
}

TEST_F(QueueTest, push19_size){
    // given
    for(int i=0;i<19;i++){
        int_queue.push(i);
    }
    // when
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 19);
}

TEST_F(QueueTest, push19_pull10_and_size){
    // given
    for(int i=0;i<19;i++){
        int_queue.push(i);
    }
    for(int i=0;i<10;i++){
        int_queue.pull();
    }
    // when
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 9);
}

TEST_F(QueueTest, push19_pull10_push5_and_size){
    // given
    for(int i=0;i<19;i++){
        int_queue.push(i);
    }
    for(int i=0;i<10;i++){
        int_queue.pull();
    }
    for(int i=0;i<5;i++){
        int_queue.push(i);
    }
    // when
    int size = int_queue.size();

    // then
    EXPECT_EQ(size, 14);
}