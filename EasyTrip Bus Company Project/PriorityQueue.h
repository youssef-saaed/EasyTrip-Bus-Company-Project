#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "PriorityNode.h"
#include "Helpers.h"
#include <iostream>

#define LeftC i * 2
#define RightC i * 2 + 1
#define Parent i / 2
#define MaxLifeTime 10000

template <typename T>
class PriorityQueue
{
protected:
    PriorityNode<T>* items;
    int MaxCapacity;
    int Size;
    int Order;
    int PriorityHash(int priority, int order);
    int PriorityDeHash(int priority);
public:
    PriorityQueue(int MaxCapacity);
    bool Enqueue(T item, int priority);
    bool Dequeue(T &item, int &priority);
    bool Peak(T& item);
    bool IsEmpty();
    virtual ~PriorityQueue();
};

template <typename T>
int PriorityQueue<T>::PriorityHash(int priority, int order) {
    return priority * MaxLifeTime + order;
}

template <typename T>
int PriorityQueue<T>::PriorityDeHash(int priority) {
    return priority / MaxLifeTime;
}

template <typename T>
bool PriorityQueue<T>::Peak(T& item)
{
    if (!IsEmpty())
    {
        item = items[0].value;
        return true;
    }
    return false;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int MaxCapacity)
{
    this->MaxCapacity = MaxCapacity;
    items = new PriorityNode<T>[MaxCapacity + 1];
    Size = 0;
    Order = MaxLifeTime - 1;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] items;
}

template <typename T>
bool PriorityQueue<T>::IsEmpty()
{
    return !Size;
}

template <typename T>
bool PriorityQueue<T>::Enqueue(T value, int priority)
{
    if (Size >= MaxCapacity || Order < 0) {
        return false;
    }
    Size++;
    items[Size] = PriorityNode<T>(value, PriorityHash(priority, Order));
    Order--;
    int i = Size;
    while (Parent)
    {
        if (items[i] > items[Parent]) {
            Swap(items[i], items[Parent]);
            i = Parent;
            continue;
        }
        break;
    }
    return true;
}

template <typename T>
bool PriorityQueue<T>::Dequeue(T& value, int& priority)
{
    if (IsEmpty())
    {
        return false;
    }
    value = items[1].value;
    priority = PriorityDeHash(items[1].priority);
    items[1] = items[Size];
    Size--;
    int i = 1;
    while (LeftC <= Size)
    {
        if (RightC <= Size)
        {
            if (items[RightC] >= items[LeftC] && items[RightC] > items[i])
            {
                Swap(items[i], items[RightC]);
                i = RightC;
                continue;
            }
            else if (items[LeftC] >= items[RightC] && items[LeftC] > items[i])
            {
                Swap(items[i], items[LeftC]);
                i = LeftC;
                continue;
            }
            else if (items[i] >= items[LeftC] && items[i] >= items[RightC])
            {
                break;
            }
        }
        if (items[LeftC] > items[i])
        {
            Swap(items[i], items[LeftC]);
            i = LeftC;
            continue;
        }
        break;
    }
    return true;
}

#undef LeftC
#undef RightC
#undef Parent

#endif