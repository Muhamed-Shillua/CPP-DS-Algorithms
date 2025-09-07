#pragma once
#include <iostream>
#include <stdexcept>

// A simple stack implementation using dynamic array
class Stack {
private:
    int* data;      // Pointer to the stack array
    int top;        // Index of the top element
    int capacity;   // Maximum size of the stack

public:
    // Constructor: initialize stack with given capacity
    Stack(int Capacity);

    // Destructor: free allocated memory
    ~Stack();

    // Push a new element onto the stack
    void Push(int element);

    // Pop the top element and return its value
    int Pop();

    // Get the current top element (without removing it)
    int getTop() const;

    // Check if the stack is empty
    bool isEmpty() const;

    // Check if the stack is full
    bool isFull() const;

    // Print all elements from top to bottom
    void Print() const;
};
