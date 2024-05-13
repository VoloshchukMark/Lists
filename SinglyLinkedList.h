#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "../nodes/SingleNode.h"
#include <iostream>

using namespace std;
using namespace single_node;

namespace single_linked
{
template<typename T>
class SinglyLinkedList
{
private:
    unique_ptr<Node<T>> head;
    int sizeL;
    void checkIndex(int index) const;
public:
    SinglyLinkedList();
    SinglyLinkedList(T value);
    void insertAtTheBeginning(T value);
    void insertAtEnd(T value);
    void insertAtIndex(int index, T value);
    int operator[](int index) const;
    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);
    bool search(T value) const;
    int getSize() const;
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& obj)
    {
    Node<T> *current = obj.head.get();
    os << "List data: " << endl;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next.get();
    }
    os << endl;
    return os;
}
};
}

#include "SinglyLinkedList.tpp"

#endif // SINGLYLINKEDLIST_H
