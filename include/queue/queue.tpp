#include "queue/queue.hpp"

template<class Data>
Queue<Data>::Queue() : sp(0), ep(0), count(0){
    buffer = new Data[QUEUE_SIZE];
}

template<class Data>
Queue<Data>::~Queue() {
    delete[] buffer;
}

template<class Data>
void Queue<Data>::clear() {
    sp = 0;
    ep = 0;
    count = 0;
}

template<class Data>
void Queue<Data>::push(Data data) {
    if (count == QUEUE_SIZE) throw std::overflow_error("Queue is full");


    buffer[ep] = data;
    ep = (ep + 1) % QUEUE_SIZE;
    count++;
}

template<class Data>
Data Queue<Data>::pull() {
    if (count == 0) throw std::underflow_error("Queue is empty");

    Data data = buffer[sp];
    sp = (sp + 1) % QUEUE_SIZE;
    count--;
    return data;
}

template<class Data>
Data Queue<Data>::top() {
    if (count == 0) throw std::underflow_error("Queue is empty");
    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    return (ep - sp + QUEUE_SIZE) % QUEUE_SIZE;
}