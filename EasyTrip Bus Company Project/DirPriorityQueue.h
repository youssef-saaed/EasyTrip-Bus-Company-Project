#pragma once
#include "PriorityQueue.h"

template<class T>
class DirPriorityQueue :
    public PriorityQueue<T>
{
private:
    int NumberOfDirs;
    bool Reversed;
public:
    DirPriorityQueue(int MaxCapacity, int NumberOfDirs);
    ~DirPriorityQueue();
    bool Enqueue(T item, int priority);
    bool Dequeue(T& item, int& priority);
};

template<class T>
DirPriorityQueue<T>::DirPriorityQueue(int MaxCapacity, int NumberOfDirs): PriorityQueue<T>(MaxCapacity)
{
    this->NumberOfDirs = NumberOfDirs;
    Reversed = false;
}

template<class T>
DirPriorityQueue<T>::~DirPriorityQueue()
{
}

template<class T>
bool DirPriorityQueue<T>::Enqueue(T item, int priority)
{
    if (Reversed)
    {
        return PriorityQueue<T>::Enqueue(item, priority);
    }
    else
    {
        return PriorityQueue<T>::Enqueue(item, NumberOfDirs - priority);
    }
}

template<class T>
bool DirPriorityQueue<T>::Dequeue(T &item, int &priority)
{
    bool ret = PriorityQueue<T>::Dequeue(item, priority);
    if (!Reversed)
    {
        priority = NumberOfDirs - priority;
    }
    return ret;
}