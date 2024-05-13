#include <iostream>
#include "SinglyLinkedList.h"

using namespace single_linked;

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head{nullptr}, sizeL{0} {};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T value) : head{make_unique<Node<T>>(value)}, sizeL{1} {};


template<typename T>
void SinglyLinkedList<T>::checkIndex(int index) const
{
    if(index<0 || index>=sizeL)
    {
        throw std::out_of_range("Index out of range");
    }
}

template<typename T>
void SinglyLinkedList<T>::insertAtTheBeginning(T value)
{
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
    sizeL++;
}

template<typename T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
    Node<T> *current = head.get();
    if (!current) {
        head = std::move(newNode);
        sizeL++;
        return;
    }
    while (current->next) {
        current = current->next.get();
    }
    current->next = std::move(newNode);
    sizeL++;
}


template<typename T>
void SinglyLinkedList<T>::removeFromBeginning()
{
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    head = std::move(head->next);
    --sizeL;
}

template<typename T>
void SinglyLinkedList<T>::removeFromEnd()
{
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    if (sizeL == 1) {
        head.reset();
        --sizeL;
        return;
    }
    Node<T> *current = head.get();
    while (current->next->next) {
        current = current->next.get();
    }
    current->next.reset();
    --sizeL;
}

template<typename T>
void SinglyLinkedList<T>::removeAtIndex(int index)
{
    checkIndex(index);
    if (index == 0) {
        removeFromBeginning();
        return;
    } else if (index == sizeL - 1) {
        removeFromEnd();
        return;
    }

    Node<T> *current = head.get();
    for (int i = 0; i < index - 1; i++) {
        current = current->next.get();
    }
    current->next = std::move(current->next->next);
    --sizeL;
}

template <typename T>
T SinglyLinkedList<T>::operator[](int index) const
{
    checkIndex(index);
    Node<T> *current = head.get();
    for (int i = 0; i < index; i++) {
        current = current->next.get();
    }
    return current->data;
}

template<typename T>
int SinglyLinkedList<T>::getSize() const
{
    return sizeL;
}

template<typename T>
bool SinglyLinkedList<T>::search(T value) const
{
    Node<T> *current = head.get();
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next.get();
    }
    return false;
}
