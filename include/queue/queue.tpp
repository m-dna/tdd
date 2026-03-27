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
}

template<class Data>
Data Queue<Data>::pull() {
    return buffer[sp];
}

template<class Data>
Data Queue<Data>::top() {
    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    return 0;
}