#include <iostream>

#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "InputRestrictedQueue.h"

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

    InputRestrictedQueue<int> t;
    t.insertAtEnd(12);
    t.insertAtEnd(431);
    t.insertAtEnd(654);
    t.insertAtEnd(65134);
    t.insertAtEnd(1123);
    t.insertAtEnd(1234);
    t.insertAtEnd(324);
    t.insertAtEnd(98);
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtEnd();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;
    t.removeAtTheBeginning();
    cout<<t.peek()<<endl;

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
//q.dequeue();
//q.dequeue();
//q.dequeue();

//Stack<int> p;
//p.push(12);
//p.push(43);
//p.push(85);
//cout<<p.peek()<<endl;
//p.pop();
//cout<<p.peek()<<endl;
//p.pop();
//cout<<p.peek()<<endl;

//Stack<Mark> f;
//f.push(Mark("First"));
//f.push(Mark("Second"));
//Mark first_stack = f.peek();
//first_stack.displayName();
//f.pop();
//Mark seconst_stack = f.peek();
//seconst_stack.displayName();

//    SinglyLinkedList<string> list1;
//    list1.insertAtEnd(12);
//    cout<<list1<<endl;

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
    return 0;
}
