#include "queue/queue.hpp"

template<class Data>
Queue<Data>::Queue() : sp(0), ep(0), count(0) {
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
    buffer[ep] = data;
    //가득차면 돌아와야됨
    ep = (ep+1)%QUEUE_SIZE;
    
    
    if(count == QUEUE_SIZE){
        // 가득 찼으면 가장 오래된 원소를 덮어씀
        sp = (sp + 1) % QUEUE_SIZE;
    } 
    else{
        count++;
    }
    return;
}

template<class Data>
Data Queue<Data>::pull() {
    if (count == 0) {
        throw std::invalid_argument("empty queue");
    }

    Data ret = buffer[sp];
    sp = (sp + 1) % QUEUE_SIZE;
    count--;
    return ret;
}

template<class Data>
Data Queue<Data>::top() {
    if (count == 0) {
        throw std::invalid_argument("empty queue");
    }
    return buffer[sp];
}

template<class Data>
int Queue<Data>::size() {
    return count;
}