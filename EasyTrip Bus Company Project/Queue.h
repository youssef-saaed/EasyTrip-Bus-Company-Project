#pragma once

template<typename V>
struct Node {
    V data;
    Node<V>* next;
    Node() : data(V()), next(nullptr) {}
};

template<typename T>
class Queue {
private:
    Node<T>* rear; 
    int MaxCapacity;

public:
    Queue(int capacity);
    bool isEmpty();
    void enqueue(T passenger);
    bool dequeue(T& value);
    int getMaxCapacity();
    bool isFull();
    int size();
    bool peek(T& value);
};

template<typename T>
Queue<T>::Queue(int capacity) : MaxCapacity(capacity) {
    rear = nullptr;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return (rear == nullptr);
}

template<typename T>
void Queue<T>::enqueue(T passenger) {
    if (isFull()) {
        return;
    }

    Node<T> *newNode = new Node<T>;
    newNode->data = passenger;

    if (isEmpty()) {
        newNode->next = newNode;
    }
    else {
        newNode->next = rear->next;
        rear->next = newNode;
    }

    rear = newNode;
}

template<typename T>
bool Queue<T>::dequeue(T& value) {
    if (isEmpty()) {
        return false;
    }
    else {
        Node<T>* front = rear->next;
        if (front == rear) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }
        value = front->data;
        delete front;
        return true;
    }
}

template<typename T>
inline int Queue<T>::getMaxCapacity()
{
    return MaxCapacity;
}

template<typename T>
bool Queue<T>::isFull() {
    return (MaxCapacity > 0) && (size() >= MaxCapacity);
}

template<typename T>
int Queue<T>::size() {
    if (isEmpty()) {
        return 0;
    }

    int count = 1;
    Node<T>* temp = rear->next;
    while (temp != rear) {
        count++;
        temp = temp->next;
    }

    return count;
}

template<typename T>
bool Queue<T>::peek(T& value) {
    if (isEmpty()) {
        return false;
    }
    else {
        Node<T>* front = rear->next;
        value = front->data;
        return true;
    }
}