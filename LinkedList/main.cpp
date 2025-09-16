#include "LinkedList.h"

int main() {
    LinkedList list;

    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtBeginning(5);
    list.InsertAtPos(2, 15);

    std::cout << "List: ";
    list.Display();

    list.RemoveByValue(20);
    std::cout << "After removing 20: ";
    list.Display();

    list.ReverseIterative();
    std::cout << "After reverse: ";
    list.Display();

    return 0;
}
