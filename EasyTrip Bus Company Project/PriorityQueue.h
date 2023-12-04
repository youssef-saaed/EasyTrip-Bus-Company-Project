#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "PriorityNode.h"
#include "Helpers.h"

#define LeftC i * 2
#define RightC i * 2 + 1
#define Parent i / 2

template <typename T>
class PriorityQueue
{
private:
    PriorityNode<T>* items;
    int MaxCapacity;
    int Size;
    int k;
    bool MaintainOrder(PriorityNode<T>& parent, PriorityNode<T>& child);
    void MaintainRoot(int i);
public:
    PriorityQueue(int MaxCapacity);
    bool Enqueue(T item, int priority);
    bool Dequeue(T& item, int& priority);
    bool IsEmpty();
    ~PriorityQueue();
};

template <typename T>
bool PriorityQueue<T>::MaintainOrder(PriorityNode<T>& parent, PriorityNode<T>& child)
{
    if (parent == child && parent.order > child.order)
    {
        Swap(parent, child);
        return true;
    }
    return false;
}

template <typename T>
void PriorityQueue<T>::MaintainRoot(int i)
{
    if (RightC <= Size)
    {
        if (items[RightC].order <= items[LeftC].order)
        {
            if (MaintainOrder(items[i], items[RightC]))
            {
                MaintainRoot(RightC);
            }
        }
        else
        {
            if (MaintainOrder(items[i], items[LeftC]))
            {
                MaintainRoot(LeftC);
            }
        }
    }
    else if (LeftC <= Size)
    {
        MaintainOrder(items[i], items[LeftC]);
    }
    return;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int MaxCapacity)
{
    this->MaxCapacity = MaxCapacity;
    items = new PriorityNode<T>[MaxCapacity + 1];
    Size = 0;
    k = 1;
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
    if (Size >= MaxCapacity) {
        return false;
    }
    Size++;
    items[Size] = PriorityNode<T>(value, priority, k);
    k++;
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
    priority = items[1].priority;
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
                MaintainOrder(items[i], items[LeftC]);
                i = RightC;
                continue;
            }
            else if (items[LeftC] >= items[RightC] && items[LeftC] > items[i])
            {
                Swap(items[i], items[LeftC]);
                MaintainOrder(items[i], items[RightC]);
                i = LeftC;
                continue;
            }
            else if (items[i] >= items[LeftC] && items[i] >= items[RightC])
            {
                MaintainRoot(i);
                break;
            }
        }
        if (items[LeftC] > items[i])
        {
            Swap(items[i], items[LeftC]);
            i = LeftC;
            continue;
        }
        MaintainOrder(items[i], items[LeftC]);
        break;
    }
    return true;
}

#undef LeftC
#undef RightC
#undef Parent

#endif