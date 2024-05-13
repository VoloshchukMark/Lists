#include <iostream>

#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"

using namespace std;
using namespace single_linked;

class Mark
{
private:
    string name;
    int age;
public:
    void displayName() {cout<<name<<endl;}
    Mark(string newName) : name{newName} {}
    Mark() : name{"Mark"} {}

    friend std::ostream& operator<<(std::ostream& os, Mark& obj)
    {
        os << obj.name;
    return os;
}
};


int main()
{
//    SinglyLinkedList<string> list;
//    list.insertAtEnd("12");
//    list.insertAtEnd("Mark");
//    list.insertAtEnd("999");
//    cout<<list<<endl;
//    list.insertAtTheBeginning("Piwpaw");
//    cout<<list<<endl;
//    cout<<list[2]<<endl;
//    list.removeAtIndex(2);
//    cout<<list<<endl;
//    cout<<list[2]<<endl;

//Queue<string> q;
//q.enqueue("Mark");
//q.enqueue("Smth");
//cout<<q.peek()<<endl;
//q.dequeue();
//cout<<q.peek()<<endl;

//    SinglyLinkedList<int> list1;
//    DoubleLinkedList<SinglyLinkedList<int>> dList;
//    list1.insertAtTheBeginning(12);
//    list1.insertAtEnd(53);
//    dList.insertAtBeginning(list1);

//    DoubleLinkedList<string> dList;
//    dList.insertAtEnd("Mark");
//    cout<<dList<<endl;
//    dList.insertAtBeginning("12");
//    cout<<dList<<endl;
//    dList.removeAtIndex(1);
//    cout<<dList<<endl;
//    dList.insertAtEnd("Father");
//    dList.insertAtEnd("Mewmo");
//    dList.insertAtEnd("MFart");
//    dList.insertAtBeginning("baobab");
//    cout<<dList<<endl;
//    cout<<dList[4]<<endl;
}
