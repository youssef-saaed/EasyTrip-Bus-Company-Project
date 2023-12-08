#ifndef _QUEUE_H_
#define _QUEUE_H_

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
    void enqueue(T passenger);
    Node<T>* dequeue();
    Node<T>* dequeueSpecificElement(T passenger);
    bool isFull();
    int size();
    T peek();
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

    Node<T>* newNode = new Node<T>;
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
Node<T>* Queue<T>::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    else {
        Node<T>* front = rear->next;
        if (front == rear) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }
        return front;
    }
}

template<typename T>
Node<T>* Queue<T>::dequeueSpecificElement(T passenger) {
    if (isEmpty()) {
        return nullptr;
    }
    else {
        Node<T>* current = rear->next;
        Node<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == passenger) {
                if (current == rear->next) {
                    rear->next = current->next;
                    if (current == rear) {
                        rear = nullptr;
                    }
                    delete current;
                    return current;
                }
                else {
                    previous->next = current->next;
                    if (current == rear) {
                        rear = previous;
                    }
                    delete current;
                    return current;
                }
            }
            previous = current;
            current = current->next;
        }

        return nullptr; 
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
        return T();
    }
    else {
        Node<T>* front = rear->next;
        return front->data;
    }
}

#endif
