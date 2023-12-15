#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }
    bool empty1()
    {
        return (this->top1 == -1);
    }
    bool empty2()
    {
        return (this->top2 == this->size);
    }
    void push1(int data)
    {
        if (this->top2 - this->top1 == 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        this->top1++;
        this->arr[top1] = data;
    }
    void pop1()
    {
        if (this->empty1())
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        this->arr[top1] = 0;
        this->top1--;
    }
    void push2(int data)
    {
        if (this->top2 - this->top1 == 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        this->top2--;
        this->arr[top2] = data;
    }
    void pop2()
    {
        if (this->empty2())
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        this->arr[top2] = 0;
        this->top2++;
    }
    int getTop1()
    {
        if (this->empty1())
        {
            cout << "Stack 1 is empty!" << endl;
            return -1;
        }
        return this->arr[this->top1];
    }
    int getTop2()
    {
        if (this->empty2())
        {
            cout << "Stack 2 is empty!" << endl;
            return -1;
        }
        return this->arr[this->top2];
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);

    st.push1(2);
    st.push1(6);
    st.push2(11);
    st.push2(21);
    st.push2(22);
    cout << st.getTop1() << endl;
    st.pop1();
    cout << st.empty2() << endl;
    st.print();

    return 0;
}