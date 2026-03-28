#ifndef QUEUE_HPP
#define QUEUE_HPP

#define QUEUE_SIZE 20

template<class Data>
class Queue {
private:
    int sp;
    int ep;
    Data* buffer;
    int cnt;
public:
    Queue();
    ~Queue();

    void clear();
    void push(Data);
    Data pull();
    Data top();
    int size();
};

#include "queue.tpp"

#endif