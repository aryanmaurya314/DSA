#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    // constructor to initialize Stack
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    // push an element
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    // remove an element
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }
    // get size of stack
    int getSize()
    {
        return this->top + 1;
    }
    // check if stack is empty
    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
    // get topmost element
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    // print
    void print()
    {
        cout << "Top: " << top << endl;
        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(2);

    st.push(10);
    st.push(20);
    // st.push(30);
    // st.push(40);
    st.pop();
    cout << "Top element: " << st.getTop() << endl;
    st.pop();
    cout << "Top element: " << st.getTop() << endl;

    return 0;
}