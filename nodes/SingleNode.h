#ifndef SINGLENODE_H
#define SINGLENODE_H

#include <memory>

namespace single_node
{
    template<typename T>
    class Node
    {
    public:
        T data;
        std::unique_ptr<Node> next;
        Node(T value);
    };
}
#include "SingleNode.tpp"

#endif // SINGLENODE_H
