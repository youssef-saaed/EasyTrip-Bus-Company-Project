#ifndef _PRIORITY_NODE_H_
#define _PRIORITY_NODE_H_

template <typename T>
class PriorityNode
{
public:
    T value;
    int priority;
    PriorityNode();
    PriorityNode(T value, int priority);
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
}

template <typename T>
PriorityNode<T>::PriorityNode(T value, int priority) : value(value), priority(priority)
{
}

#endif