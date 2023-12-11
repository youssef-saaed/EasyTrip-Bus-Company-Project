#pragma once

#include <stdexcept>

template<typename T>
class arrayList
{
private:
	T* array;
	int size;
	int capacity;
public:
	arrayList(int capacity);
	bool insert(T value, int index);
	bool remove(int index);
	T LookAt(int index);
	bool isempty();
	int find(T &element);
	bool push(T element);
	bool pop(T &element);
	int Size();
};

template<typename T>
inline arrayList<T>::arrayList(int capacity)
{
	this->capacity = capacity;
	size = 0;
	array = new T[capacity];
}

template<typename T>
bool arrayList<T>::insert(T value, int index)
{
	if (size >= capacity)
	{
		return false;
	}
	for (int i = size - 1; i >= index; i--) {
		array[i + 1] = array[i];
	}
	array[index] = value;
	size++;
	return true;
}

template<typename T>
inline bool arrayList<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return false;
	}
	for (int i = index; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
	return true;
}

template<typename T>
inline T arrayList<T>::LookAt(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::invalid_argument("LookAt index out of range");
	}
	return array[index];
}

template<typename T>
inline bool arrayList<T>::isempty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
int arrayList<T>::find(T& element)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
bool arrayList<T>::push(T element)
{
	if (size >= capacity)
	{
		return false;
	}
	insert(element, size);
	return true;
}

template<typename T>
bool arrayList<T>::pop(T& element)
{
	if (isempty)
	{
		return false;
	}
	element = LookAt(size - 1);
	remove(size - 1);
	return true;
}

template<typename T>
inline int arrayList<T>::Size()
{
	return size;
}



