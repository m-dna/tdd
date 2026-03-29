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
    if (is_full()) {
        throw std::runtime_error("Queue is full");
    }
    
    buffer[ep] = data;
    ep = (ep + 1) % QUEUE_SIZE;
}

template<class Data>
Data Queue<Data>::pull() {
    if (is_empty()) {
        throw std::runtime_error("Queue is empty");
    }

    Data result = buffer[sp];
    sp = (sp + 1) % QUEUE_SIZE;
    return result;
}

template<class Data>
Data Queue<Data>::top() {
    if (is_empty()) {
        throw std::runtime_error("Queue is empty");
    }

    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    return (ep - sp + QUEUE_SIZE) % QUEUE_SIZE;
}

template<class Data>
bool Queue<Data>::is_full() {
    return ep == (sp - 1 + QUEUE_SIZE) % QUEUE_SIZE;
}

template<class Data>
bool Queue<Data>::is_empty() {
    return sp == ep;
}