#include <iostream>
#include "DoubleLinkedList.h"

using namespace double_node;

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0} {};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(T value) : head{make_shared<double_node::Node<T>>(value)}, tail{head}, size{1} {};


template<typename T>
void DoubleLinkedList<T>::checkIndex(int index) const
{
    if (index < 0 || index >= size) {
        throw out_of_range("Failed to access element. Index out of range!");
    }
}

template<typename T>
void DoubleLinkedList<T>::insertAtBeginning(T value)
{
    shared_ptr<double_node::Node<T>> newNode = make_shared<double_node::Node<T>>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    ++size;
}

template<typename T>
void DoubleLinkedList<T>::insertAtEnd(T value)
{
    shared_ptr<double_node::Node<T>> newNode = make_shared<double_node::Node<T>>(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    ++size;
}

template<typename T>
void DoubleLinkedList<T>::insertAtIndex(int index, T value)
{
    checkIndex(index);
    if (index == 0) {
        insertAtBeginning(value);
    }
    if (index == size) {
        insertAtEnd(value);
    }
    shared_ptr<double_node::Node<T>> newNode = make_shared<double_node::Node<T>>(value);
    shared_ptr<double_node::Node<T>> current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->previous = current;
    current->next->previous = newNode;
    current->next = newNode;
    ++size;
}

template<typename T>
T DoubleLinkedList<T>::operator[](int index) const
{
    checkIndex(index);
    shared_ptr<double_node::Node<T>> current = head;
    for (int i = 0; i <= index - 1; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void DoubleLinkedList<T>::removeFromBeginning()
{
    if (!head) {
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::removeFromEnd()
{
    if (!tail) {
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::removeAtIndex(int index)
{
    checkIndex(index);
    if (index == 0) {
        head = head->next;
        if (head) {
            head->previous.reset();
        } else {
            tail.reset();
        }
    } else if (index == size - 1) {
        tail = tail->previous.lock();
        tail->next.reset();
    } else {
        shared_ptr<double_node::Node<T>> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous.lock()->next = current->next;
        current->next->previous = current->previous;
    }
    --size;
}

template<typename T>
bool DoubleLinkedList<T>::search(T value) const
{
    shared_ptr<double_node::Node<T>> current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
int DoubleLinkedList<T>::getSize() const
{
    return size;
}
