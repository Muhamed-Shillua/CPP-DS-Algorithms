#include "LinkedList.h"

// Constructor: initialize empty list
LinkedList::LinkedList() {
    Head = Tail = nullptr;
    Length = 0;
}

// Destructor: delete all nodes to free memory
LinkedList::~LinkedList() {
    Node* Current = Head;
    while (Current != nullptr) {
        Node* Next = Current->NextPtr;
        delete Current;
        Current = Next;
    }
    Head = Tail = nullptr;
    Length = 0;
}

// ====================== UTILITY ======================

// Check if the list is empty
bool LinkedList::isEmpty() const { return Length == 0; }

// Return length of the list
int LinkedList::GetLength() const { return Length; }

// Display all elements in the list
void LinkedList::Display() const {
    Node* Temp = Head;
    std::cout << "[ ";
    while (Temp != nullptr) {
        std::cout << Temp->Data;
        if (Temp->NextPtr != nullptr) std::cout << " -> ";
        Temp = Temp->NextPtr;
    }
    std::cout << " ]" << std::endl;
}

// Search if an element is in the list
int LinkedList::Search(int Element)const {
    Node* Temp = Head;
    int Pos = 0;
    while (Temp != nullptr) {
        if (Temp->Data == Element) return Pos;
        Temp = Temp->NextPtr;
        Pos++;
    }
    return -1;    // Return -1 if the elemnet not found
}

// Reverse the linked list (Iterative Method)
void LinkedList::ReverseIterative() {
    Node* Prev = nullptr;
    Node* Current = Head;
    Node* Next = nullptr;

    Tail = Head; // old head becomes new tail

    while (Current != nullptr) {
        Next = Current->NextPtr;   // save next
        Current->NextPtr = Prev;   // reverse link
        Prev = Current;            // move Prev
        Current = Next;            // move Current
    }

    Head = Prev; // new head
}

// ====================== INSERT ======================

// Insert element at the beginning
void LinkedList::InsertAtBeginning(int Value) {
    Node* NewNode = new Node;
    NewNode->Data = Value;

    if (isEmpty()) {
        Head = Tail = NewNode;
        NewNode->NextPtr = nullptr;
    }
    else {
        NewNode->NextPtr = Head; // link to old head
        Head = NewNode;          // update head
    }
    Length++;
}

// Insert element at the end
void LinkedList::InsertAtEnd(int Value) {
    Node* NewNode = new Node;
    NewNode->Data = Value;
    NewNode->NextPtr = nullptr; // last node points to nullptr

    if (isEmpty()) {
        Head = Tail = NewNode;
    }
    else {
        Tail->NextPtr = NewNode; // link old tail to new node
        Tail = NewNode;          // update tail
    }
    Length++;
}

// Insert element at a specific position
void LinkedList::InsertAtPos(int Pos, int Value) {
    if (Pos < 0 || Pos > Length) {
        throw std::out_of_range("Invalid position!");
    }

    if (Pos == 0) {
        InsertAtBeginning(Value);
        return;
    }
    if (Pos == Length) {
        InsertAtEnd(Value);
        return;
    }

    Node* NewNode = new Node;
    NewNode->Data = Value;

    Node* Current = Head;
    for (int i = 1; i < Pos; i++) {
        Current = Current->NextPtr;
    }

    NewNode->NextPtr = Current->NextPtr;
    Current->NextPtr = NewNode;

    Length++;
}

// ====================== REMOVE ======================

// Remove from the beginning
void LinkedList::RemoveBeginning() {
    if (isEmpty()) { throw std::underflow_error("List is empty!"); }

    if (Length == 1) {
        delete Head;
        Head = Tail = nullptr;
    }
    else {
        Node* Temp = Head;
        Head = Head->NextPtr;
        delete Temp;
    }
    Length--;
}

// Remove from the end
void LinkedList::RemoveEnd() {
    if (isEmpty()) { throw std::underflow_error("List is empty!"); }

    if (Length == 1) {
        delete Head;
        Head = Tail = nullptr;
    }
    else {
        Node* Current = Head;
        Node* Prev = nullptr;

        while (Current != Tail) {
            Prev = Current;
            Current = Current->NextPtr;
        }
        delete Current;
        Prev->NextPtr = nullptr;
        Tail = Prev;
    }
    Length--;
}

// Remove by value
void LinkedList::RemoveByValue(int Value) {
    if (isEmpty()) { throw std::underflow_error("List is empty!"); }

    if (Head->Data == Value) {
        RemoveBeginning();
        return;
    }

    Node* Current = Head->NextPtr;
    Node* Prev = Head;

    while (Current != nullptr) {
        if (Current->Data == Value) {
            Prev->NextPtr = Current->NextPtr;
            if (Current == Tail) Tail = Prev;
            delete Current;
            Length--;
            return;
        }
        Prev = Current;
        Current = Current->NextPtr;
    }

    std::cout << "Element not found" << std::endl;
}
