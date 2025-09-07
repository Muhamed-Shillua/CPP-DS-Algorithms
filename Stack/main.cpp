#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    try {
        Stack st(5);

        st.Push(10);
        st.Push(20);
        st.Push(30);

        st.Print(); // Stack: 30, 20, 10

        cout << "Top: " << st.getTop() << endl; // 30

        cout << "Popped: " << st.Pop() << endl; // 30
        st.Print(); // Stack: 20, 10

        st.Push(40);
        st.Push(50);
        st.Push(60);
        st.Print(); // Stack: 60, 50, 40, 20, 10

        // This will throw exception
        st.Push(70);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
