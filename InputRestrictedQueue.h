#ifndef INPUTRESTRICTEDQUEUE_H
#define INPUTRESTRICTEDQUEUE_H

#include "../nodes/DoubleNode.h"
#include <iostream>

using namespace double_node;
using namespace std;

template<typename T>
class InputRestrictedQueue
{
private:
    shared_ptr<double_node::Node<T>> front;
    shared_ptr<double_node::Node<T>> rear;
public:
    InputRestrictedQueue();

    void insertAtEnd(T value);
    void removeAtTheBeginning();
    void removeAtEnd();
    T peek();
    bool isEmpty();
};

#include "InputRestrictedQueue.tpp"

#endif // INPUTRESTRICTEDQUEUE_H
