#include <iostream>
#include "InputRestrictedQueue.h"

using namespace double_node;

template<typename T>
InputRestrictedQueue<T>::InputRestrictedQueue() : front(nullptr), rear(nullptr) {}

template<typename T>
void InputRestrictedQueue<T>::insertAtEnd(T value)
{
    shared_ptr<double_node::Node<T>> temp = make_shared<double_node::Node<T>>(value);
    if (rear == nullptr) {
            front = rear = temp;
            return;
    }
    rear->next = temp;
    rear = temp;
}

template<typename T>
void InputRestrictedQueue<T>::removeAtTheBeginning()
{
    if (front == nullptr) {
        cout<<"The queue is empty."<<endl;
        return;
    }
    T frontData = front->data;
    front = std::move(front->next);
    if (front == nullptr)
        rear = nullptr;
    cout<<"Object '"<<frontData<<"' has been removed from queue."<<endl;
    return;
}

template<typename T>
void InputRestrictedQueue<T>::removeAtEnd()
{
    if (rear == front)
    {
        rear = front = nullptr;
    }
    double_node::Node<T> *current = front.get();
    while (current->next->next) {
        current = current->next.get();
    }
    current->next.reset();
//    T rearData = rear->data;
//    rear = rear->previous.lock();
//    rear->next = nullptr;
//    cout<<rear<<" Bruh"<<endl;
//    if (rear == nullptr)
//        front = nullptr;
    cout<<"Object '"<<*current<<"' has been removed from queue."<<endl;
    return;
}

template<typename T>
T InputRestrictedQueue<T>::peek()
{
    if (front != nullptr) {
        return front->data;
    } else {
        std::cout << "Queue is empty." << std::endl;
        return T();
    }
}

template<typename T>
bool InputRestrictedQueue<T>::isEmpty()
{
    return (front == nullptr);
}
