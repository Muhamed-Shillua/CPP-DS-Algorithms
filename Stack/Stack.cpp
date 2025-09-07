#include "Stack.h"

// Constructor
Stack::Stack(int Capacity) : top(-1), capacity(Capacity) {
    data = new int[capacity];
}

// Destructor
Stack::~Stack() {
    delete[] data;
}

// Push a new element
void Stack::Push(int element) {
    if (isFull()) throw std::overflow_error("Stack Overflow!");
    data[++top] = element;
}

// Pop the top element and return its value
int Stack::Pop() {
    if (isEmpty()) throw std::underflow_error("Stack Underflow!");
    return data[top--];
}

// Get the top element
int Stack::getTop() const {
    if (isEmpty()) throw std::runtime_error("Stack is empty!");
    return data[top];
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return top == -1;
}

// Check if stack is full
bool Stack::isFull() const {
    return top == capacity - 1;
}

// Print stack elements from top to bottom
void Stack::Print() const {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    std::cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        std::cout << data[i] << (i > 0 ? ", " : "");
    }
    std::cout << std::endl;
}
