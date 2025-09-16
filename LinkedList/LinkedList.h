#pragma once
#include <iostream>

// A simple singly linked list implementation
class LinkedList
{
private:
    struct Node
    {
        int Data;        // node value
        Node* NextPtr;   // pointer to the next node
    };

    Node* Head;   // pointer to the first node
    Node* Tail;   // pointer to the last node
    int Length;   // number of nodes in the list

public:
    // Constructor
    LinkedList();

    // Destructor: free all nodes
    ~LinkedList();

    // Check if the list is empty
    bool isEmpty() const;

    // Insert methods
    void InsertAtBeginning(int Value);
    void InsertAtEnd(int Value);
    void InsertAtPos(int Pos, int Value);

    // Remove methods
    void RemoveBeginning();
    void RemoveEnd();
    void RemoveByValue(int Value);

    // Utility methods
    void Display() const;
    int GetLength() const;
    void ReverseIterative();
};
