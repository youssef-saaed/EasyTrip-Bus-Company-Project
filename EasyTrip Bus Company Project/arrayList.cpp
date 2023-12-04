#include "arrayList.h"
template<typename T>
inline arrayList<T>::arrayList()
{
	capacity = 100;
	size = 0;
	array = new T[capacity];
}

template<typename T>
void arrayList<T>::insert(T value, int index)
{

	for (int i = size - 1; i >= index; i--) {
		array[i + 1] = array[i];
	}
	array[index] = value;
	size++;
}

template<typename T>
inline void arrayList<T>::remove(int index)
{

	for (int i = index; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	size--;
}

template<typename T>
inline T arrayList<T>::LookAt(int index)
{
	return array[index];
}

template<typename T>
inline bool arrayList<T>::isempty()
{
	if (size == 0) {
		return true;
	}
	return false;
}

template<typename T>
inline bool arrayList<T>::isfull()
{
	if (size == capacity) {
		capacity = capacity * 2;
		return true;
	}
	return false;
}