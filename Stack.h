#ifndef STACK_H
#define STACK_H

#include "../nodes/DoubleNode.h"
#include <iostream>

using namespace std;
using namespace double_node;

template<typename T>
class Stack {
private:
    std::shared_ptr<double_node::Node<T>> top;
public:
    Stack();
    Stack(T data);
    void push(T data);
    void pop();
    T peek();
    bool isEmpty();
};

#include "Stack.tpp"

#endif // STACK_H
