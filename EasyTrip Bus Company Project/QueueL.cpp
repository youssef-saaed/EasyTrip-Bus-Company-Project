#include "Queue.h"

template<typename T>
Queue<T>::Queue(int capacity) : MaxCapacity(capacity) {
    rear = nullptr;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return (rear == nullptr);
}

template<typename T>
void Queue<T>::enqueue(T value) {
    if (isFull()) {
        // cout << "Queue is full" << endl;
        return;
    }

    Node<T>* newNode = new Node<T>;
    newNode->data = value;

    if (isEmpty()) {
        newNode->next = newNode; 
    } else {
        newNode->next = rear->next;
        rear->next = newNode; 
    }

    rear = newNode; 
}

template<typename T>
Node<T>* Queue<T>::dequeue() {
    if (isEmpty()) {
        // cout << "Queue is empty" << endl;
        return nullptr;
    } else {
        Node<T>* front = rear->next;
        if (front == rear) {
            rear = nullptr; 
        } else {
            rear->next = front->next; 
        }
        return front;
    }
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
T Queue<T>::peek() {
    if (isEmpty()) {
        // cout << "Queue is empty" << endl;
        return T();
    } else {
        Node<T>* front = rear->next;
        return front->data;
    }
}
