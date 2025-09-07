#pragma once
#include <iostream>
using namespace std;

template<class T> // for generic values

// A simple stack implementation using linked list
class Stack
{
private:
    struct Node
    {
        T Value;       // the value
        Node* NextPtr; // the pointer to next node
    };

    Node* TopPtr;     // pointer to the top node
    Node* CurrentPtr; // pointer for traversal or temporary use

    // Check if the stack is empty
    bool isEmpty();

public:
    // Constructor: initialize empty stack
    Stack();

    // Push a new element onto the stack
    void Push(T newValue);

    // Pop the top element from the stack
    void Pop();

    // Get the top element without removing it
    T getTop();

    // Print all elements from top to bottom
    void Print();
};

// ================= Implementation =================

template<class T>
Stack<T>::Stack() { TopPtr = nullptr; }

template<class T>
bool Stack<T>::isEmpty() { return TopPtr == nullptr; }

template<class T>
void Stack<T>::Push(T NewValue)
{
    Node* NewNode = new Node; // create new node
    if (!NewNode) std::cout << "Stack push cannot allocate memory" << std::endl;
    else
    {
        NewNode->Value = NewValue;      // store value
        NewNode->NextPtr = TopPtr;      // link to previous top
        TopPtr = NewNode;               // update top pointer
    }
}

template<class T>
void Stack<T>::Pop()
{
    if (isEmpty()) std::cout << "error!..Stack is empty." << std::endl;
    else
    {
        CurrentPtr = TopPtr;            // save top node
        TopPtr = TopPtr->NextPtr;       // move top pointer down
        delete CurrentPtr;              // free memory
    }
}

template<class T>
T Stack<T>::getTop()
{
    if (isEmpty()) throw std::runtime_error("error!..Stack is empty.");
    return TopPtr->Value;               // return top value
}

template<class T>
void Stack<T>::Print()
{
    if (isEmpty()) std::cout << "error!..Stack is empty." << std::endl;
    else
    {
        CurrentPtr = TopPtr;            // start from top
        std::cout << "Stack elements (top to bottom): [ ";
        while (CurrentPtr)
        {
            std::cout << CurrentPtr->Value << " "; // print value
            CurrentPtr = CurrentPtr->NextPtr;      // move to next node
        }
        std::cout << "]" << std::endl;
    }
}
