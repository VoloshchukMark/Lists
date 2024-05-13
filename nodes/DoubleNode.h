#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include <memory>

namespace double_node
{
    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> previous;

        Node(T value) : data{value} {}
    };
}

#endif // DOUBLENODE_H
