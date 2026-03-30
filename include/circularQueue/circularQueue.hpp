#ifndef circularQueue_HPP
#define circularQueue_HPP

int arr;

class CirQueue {
public:
  void enqueue();
  void dequeue();
  bool isEmpty();
  bool isFull();
  int size();

};

#endif // circularQueue_HPP