#include "queue/queue.hpp"

template<class Data>
Queue<Data>::Queue() : sp(0), ep(0) {
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
}

template<class Data>
void Queue<Data>::push(Data data) {
    if((ep+1)%QUEUE_SIZE==sp) throw std::overflow_error("Queue is full");
    buffer[ep] = data;
    ep=(ep+1)%QUEUE_SIZE;
}

template<class Data>
Data Queue<Data>::pull() {
    if(ep==sp) throw std::underflow_error("Queue is empty");
    Data tmp = buffer[sp];
    sp=(sp+1)%QUEUE_SIZE;
    return tmp;
}

template<class Data>
Data Queue<Data>::top() {
    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    int size = (ep-sp+QUEUE_SIZE)%QUEUE_SIZE;
    return size;
}