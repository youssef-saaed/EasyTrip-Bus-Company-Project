#ifndef _PRIORITYQUEUE2D_H_
#define _PRIORITYQUEUE2D_H_

#include "PriorityQueue.h"

#define MaxPriority 100

template <typename T>
class PriorityQueue2D : public PriorityQueue<T>
{
private:
	int MaxDim2;
	bool Reversed;
	int PriorityHash2D(int dim2, int priority);
	void PriorityDeHash2D(int &priority, int &dim2);
public:
	PriorityQueue2D(int MaxCapacity, int MaxDim2, bool Reversed = false);
	~PriorityQueue2D();
	bool Enqueue2D(T item, int dim2, int priority);
	bool Dequeue2D(T &item, int &dim2, int &priority);
};

template <typename T>
PriorityQueue2D<T>::PriorityQueue2D(int MaxCapacity, int MaxDim2, bool Reversed) : PriorityQueue(MaxCapacity)
{
	this->MaxDim2 = MaxDim2;
	this->Reversed = Reversed;
}

template <typename T>
PriorityQueue2D<T>::~PriorityQueue2D()
{
}

template <typename T>
int PriorityQueue2D<T>::PriorityHash2D(int dim2, int priority)
{
	return MaxPriority * dim2 + priority;
}

template <typename T>
void PriorityQueue2D<T>::PriorityDeHash2D(int &priority, int &dim2)
{
	dim2 = priority / MaxPriority;
	if (!Reversed)
	{
		dim2 = MaxDim2 - dim2;
	}
	priority = priority % MaxPriority;
}

template <typename T>
bool PriorityQueue2D<T>::Enqueue2D(T item, int dim2, int priority)
{
	if (priority >= MaxPriority || priority < 0) {
		return false;
	}
	if (!Reversed)
	{
		dim2 = MaxDim2 - dim2;
	}
	return Enqueue(item, PriorityHash2D(dim2, priority));
}

template <typename T>
bool PriorityQueue2D<T>::Dequeue2D(T& item, int& dim2, int& priority)
{
	if (Dequeue(item, priority))
	{
		PriorityDeHash2D(priority, dim2);
		return true;
	}
	return false;
}

#endif

