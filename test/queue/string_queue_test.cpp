#include <gtest/gtest.h>
#include <string>
#include "queue/queue.hpp"

using namespace std;

class StringQueueTest : public ::testing::Test {
protected:
    Queue<string> string_queue;

    void SetUp() override {
        string_queue.clear();
    }

    void TearDown() override {
    }
};

TEST_F(StringQueueTest, push_and_top) {    
    // given
    string value = "hello";
    string_queue.push(value);

    // when
    string top = string_queue.top();

    // then
    EXPECT_EQ(top, value);
}

TEST_F(StringQueueTest, push_and_pull) {    
    // given
    string v1 = "hello";
    string v2 = "world";
    string_queue.push(v1);
    string_queue.push(v2);

    // when
    string_queue.pull();
    string second = string_queue.pull();

    // then
    EXPECT_EQ(second, v2);
}

TEST_F(StringQueueTest, size) {    
    // given
    string_queue.push("hello");
    string_queue.push("world");
    string_queue.push("!");

    // when
    int size = string_queue.size();

    // then
    EXPECT_EQ(size, 3);
}

TEST_F(StringQueueTest, clear) {    
    // given
    string_queue.push("hello");
    string_queue.push("world");
    string_queue.push("!");

    // when
    string_queue.clear();
    int size = string_queue.size();

    // then
    EXPECT_EQ(size, 0);
}