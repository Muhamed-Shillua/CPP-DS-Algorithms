#pragma once
#include <iostream>

template<class T> // for generic values

// A simple Queue implementation using linked list
class Queue
{
private:
    struct Node
    {
        T Value;       // the value
        Node* NextPtr; // the pointer to next node
    };

    Node* Front;     // pointer to the first node
    Node* Rear; // pointer for the last node

public:
    // Constructor: initialize empty queue
    Queue();

    // Check if the Queue is empty
    bool isEmpty() const;

    // Add a new element onto the queue
    void Enqueue(T newValue);

    // Remove the first element from the queue
    void Dequeue();

    // Get the fisrt element without removing it
    T Peek() const;

    // Print all elements
    void Print() const;

    ~Queue();               // Destructor
};

// ================= Implementation =================

template<class T>
Queue<T>::Queue() { Front = Rear = nullptr; }

template<class T>
bool Queue<T>::isEmpty() const { return Front == nullptr; }

template<class T>
void Queue<T>::Enqueue(T NewValue)
{
    // Create a new node for the incoming value
    Node* NewNode = new Node;
    if (!NewNode) {
        std::cout << "Queue push cannot allocate memory" << std::endl;
        return;
    }

    // Assign value and set next pointer to nullptr
    NewNode->Value = NewValue;
    NewNode->NextPtr = nullptr;

    if (isEmpty()) {
        // Special case: queue is empty
        Front = Rear = NewNode;
    }
    else {
        // General case: attach the new node at the end
        // Update Rear to point to the new last node
        Rear->NextPtr = NewNode;
        Rear = NewNode;
    }
}

template<class T>
void Queue<T>::Dequeue()
{
    if (isEmpty()) throw std::runtime_error("error!..Queue is empty.");
    else {
        // Temporary pointer to hold the front node
        Node* Temp = Front;

        // Move Front pointer to the next node
        Front = Front->NextPtr;

        // Disconnect the old front node from the list
        Temp->NextPtr = nullptr;

        // If the queue becomes empty, update Rear as well
        if (Front == nullptr) {
            Rear = nullptr;
        }

        // Free memory of the removed node
        delete Temp;
    }
}

template<class T>
T Queue<T>::Peek() const
{
    if (isEmpty()) throw std::runtime_error("error!..Queue is empty.");
    return Front->Value;               // return front value
}

template<class T>
void Queue<T>::Print() const
{
    if (isEmpty()) throw std::runtime_error("error!..Queue is empty.");
    
    // Start from the front node
    Node* Current = Front;

    std::cout << "Queue elements (Front -> Rear): ";
    while (Current != nullptr) {
        std::cout << Current->Value << " ";
        Current = Current->NextPtr;
    }
}

template<class T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        Dequeue();
    }
}
