#include <iostream>
#include "Queue.h"

using namespace double_node;

template<typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}


template<typename T>
void Queue<T>::enqueue(T data)
{
    shared_ptr<double_node::Node<T>> temp = make_shared<double_node::Node<T>>(data);
    if (rear == nullptr) {
            front = rear = temp;
            return;
    }
    rear->next = temp;
    rear = temp;
}

template<typename T>
void Queue<T>::dequeue() {
    if (front == nullptr) {
        std::cout << "Черга порожня." << std::endl;
        return;
    }
    front = std::move(front->next);
    if (front == nullptr)
        rear = nullptr;
}

template<typename T>
T Queue<T>::peek()
{
    if (front != nullptr) {
        return front->data;
    } else {
        std::cout << "Черга порожня." << std::endl;
        return T();
    }
}


template<typename T>
bool Queue<T>::isEmpty() {
    return (front == nullptr);
}
