#pragma once
#include <iostream>
#include <stdexcept>

// A simple Queue implementation using dynamic array
class Queue
{
private:
	int* Data;
	int _Front, _Rear;
	int _Size, _Capacity;

	// check if queue is empty
	bool isEmpty()const;

	// check if queue is full
	bool isFull()const;
public:
	// Constructor: initialize queue with given capacity
	Queue(int capacity);

	// Add element at the end of the queue
	void Enqueue(int element);

	// Remove element form the begining
	int Dequeue();

	// Get the first element of the queue (front)
	int Peak()const;

	// Print all elements in the queue from Front to Rear
	void Print() const;
	// Destructor: free allocated memory
	~Queue();
};

