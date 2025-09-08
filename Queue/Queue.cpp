#include "Queue.h"

// Constructor
Queue::Queue(int capacity) : _Front(0), _Rear(-1), _Size(0), _Capacity(capacity) {
    Data = new int[_Capacity];
}

// Check if queue is empty
bool Queue::isEmpty() const { return _Size == 0; }

// Check if queue is full
bool Queue::isFull() const { return _Size == _Capacity; }

// Add element at the end of the queue
void Queue::Enqueue(int element) {
    if (isFull()) {
        std::cout << "Can't add elements..Queue is full" << std::endl;
        return;
    }
    _Rear = (_Rear + 1) % _Capacity;  // move rear
    Data[_Rear] = element;
    _Size++;
}


// Remove element form the begining (fornt)
int Queue::Dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty!");
    }
    int val = Data[_Front];
    _Front = (_Front + 1) % _Capacity;  // move front
    _Size--;
    return val;
}

// Get the first element of the queue (front)
int Queue::Peak() const { return Data[_Front]; }


// Print all elements in the queue from Front to Rear
void Queue::Print() const {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    std::cout << "Queue: ";
    int count = _Size;
    int i = _Front;

    while (count > 0) {
        std::cout << Data[i] << (count > 1 ? ", " : "");
        i = (i + 1) % _Capacity;  // move circularly
        count--;
    }

    std::cout << std::endl;
}


// Destructor: free allocated memory
Queue::~Queue() { delete[] Data; }
