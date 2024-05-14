#include <iostream>
#include "Stack.h"

using namespace double_node;

template<typename T>
Stack<T>::Stack() : top(nullptr) {}

template<typename T>
Stack<T>::Stack(T data)
{
    std::shared_ptr<double_node::Node<T>> newNode = std::make_shared<double_node::Node<T>>(data);
    top = newNode;
}

template<typename T>
void Stack<T>::push(T data)
{
    std::shared_ptr<double_node::Node<T>> newNode = std::make_shared<double_node::Node<T>>(data);
    if (top != nullptr) {
        newNode->next = top;
    }
    top = newNode;
}

template<typename T>
void Stack<T>::pop()
{
    if (top != nullptr) {
        top = top->next;
    }
}

template<typename T>
T Stack<T>::peek()
{
    if (top != nullptr) {
        return top->data;
    }
    return T();
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}
