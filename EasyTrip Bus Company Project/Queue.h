#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

template<typename V>
struct Node {
    V data;
    Node<V>* next;
};

template<typename T>
class Queue {
private:
    Node<T>* rear; 
    int MaxCapacity;

public:
    Queue(int capacity);
    bool isEmpty();
    void enqueue(T value);
    Node<T>* dequeue();
    bool isFull();
    int size();
    T peek();
};

#endif
