#ifndef _PRIORITY_NODE_H_
#define _PRIORITY_NODE_H_

template <typename T>
class PriorityNode
{
public:
    T value;
    int priority;
    int order;
    PriorityNode();
    PriorityNode(T value, int priority, int order);
    bool operator>(PriorityNode<T> x);
    bool operator==(PriorityNode<T> x);
    bool operator>=(PriorityNode<T> x);
};

template <typename T>
bool PriorityNode<T>::operator>(PriorityNode<T> x)
{
    return priority > x.priority;
}

template <typename T>
bool PriorityNode<T>::operator==(PriorityNode<T> x)
{
    return priority == x.priority;
}

template <typename T>
bool PriorityNode<T>::operator>=(PriorityNode<T> x)
{
    return priority >= x.priority;
}

template <typename T>
PriorityNode<T>::PriorityNode()
{
    priority = 0;
    order = 1;
}

template <typename T>
PriorityNode<T>::PriorityNode(T value, int priority, int order) : value(value), priority(priority), order(order)
{
}

#endif