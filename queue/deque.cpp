/*
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_front(10);
    dq.push_back(11);

    cout << "Front: " << dq.front() << " Back: " << dq.back() << endl;

    cout << "Size: " << dq.size() << " IsEmpty: " << dq.empty() << endl;

    return 0;
}
*/
#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int size;

public:
    int front;
    int rear;

    Deque(int size)
    {
        int *arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_front(int data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Overflow" << endl;
        }
        else if (front == 0 && rear < size - 1)
        {
            front = size - 1;
            arr[front] = data;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else
        {
            front--;
            arr[front] = data;
        }
    }

    void push_back(int data)
    {
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "Overflow" << endl;
        }
        else if (rear == size - 1 && front > 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop_front()
    {
        if (front == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = 0;
            front = 0;
        }
        else
        {
            arr[front] = 0;
            front++;
        }
    }

    void pop_back()
    {
        if (rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (rear == front)
        {
            arr[rear] = 0;
            rear = -1;
            front = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = 0;
            rear = size - 1;
        }
        else
        {
            arr[rear] = 0;
            rear--;
        }
    }

    void print()
    {
        cout << "Printing: Deque: ";
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deque dq(3);

    dq.push_back(3);
    dq.print();
    dq.push_back(4);
    dq.print();
    dq.push_front(5);
    dq.print();
    dq.pop_front();
    dq.print();

    return 0;
}