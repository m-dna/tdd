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
    if (size() >= QUEUE_SIZE - 1) {
        throw std::overflow_error("Queue is full");
    }
    buffer[ep] = data;
    ep = (ep + 1) % QUEUE_SIZE;
}

template<class Data>
Data Queue<Data>::pull() {
    if (size() == 0) {
        throw std::underflow_error("Queue is empty");
    }
    Data data = buffer[sp];
    sp = (sp + 1) % QUEUE_SIZE;
    return data;
}

template<class Data>
Data Queue<Data>::top() {
    if (size() == 0) {
        throw std::underflow_error("Queue is empty (top)");
    }
    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    if (ep >= sp) {
        return ep - sp;
    } else {
        return QUEUE_SIZE - sp + ep;
    }
}