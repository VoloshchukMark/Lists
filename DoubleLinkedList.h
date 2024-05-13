#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


#include "../nodes/DoubleNode.h"
#include <iostream>
using namespace std;
using namespace double_node;

template<typename T>
class DoubleLinkedList
{
private:
    shared_ptr<double_node::Node<T>> head;
    shared_ptr<double_node::Node<T>> tail;
    int size;
    void checkIndex(int index) const;
public:
    DoubleLinkedList();// : head{nullptr}, tail{nullptr}, size{0} {};
    DoubleLinkedList(T value);// : head{make_shared<Node<T>>(value)}, tail{head}, size{1} {};
    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtIndex(int index, T value);
    T operator[](int index) const;
    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);
    bool search(T value) const;
    int getSize() const;
    friend ostream &operator<<(ostream &os, DoubleLinkedList &obj)
    {
        os << "List data: " << endl;
        shared_ptr<double_node::Node<T>> current = obj.head;
        do{
            os << current->data << " ";
            current = current->next;
        } while (current);
        os << endl;
        return os;
    }
};

#include "DoubleLinkedList.tpp"

#endif // DOUBLELINKEDLIST_H
