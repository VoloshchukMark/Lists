#ifndef QUEUE_H
#define QUEUE_H

#include "../nodes/DoubleNode.h"
#include <iostream>

using namespace std;
using namespace double_node;

template<typename T>
class Queue
{
private:
    shared_ptr<double_node::Node<T>> front;
    shared_ptr<double_node::Node<T>> rear;
public:
    Queue();

    void enqueue(T data);
    void dequeue();
    T peek();
    bool isEmpty();
};

#include "Queue.tpp"

#endif // QUEUE_H
