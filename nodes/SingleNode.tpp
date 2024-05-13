#include "../nodes/SingleNode.h"

using namespace single_node;

template<typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}

