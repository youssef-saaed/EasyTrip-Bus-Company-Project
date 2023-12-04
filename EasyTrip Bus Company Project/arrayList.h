#pragma once
template<typename T>
class arrayList
{
private:
	T* array;
	int size;
	int capacity;
public:
	arrayList();
	void insert(T value, int index);
	void remove(int index);
	T LookAt(int index);
	bool isempty();
	bool isfull();

};


