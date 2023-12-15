#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;

public:
    int front;
    int rear;
    CircularQueue(int size)
    {
        int *arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }
    void push(int data)
    {
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "Can't insert. Queue is full!" << endl;
        }
        else if (this->empty())
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front > 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    bool empty()
    {
        return front == -1 && rear == -1;
    }
    int getSize()
    {
        return this->empty() ? 0 : abs(this->rear - this->front + 1);
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Can't pop. Queue is empty!" << endl;
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
            arr[this->front] = 0;
            this->front++;
        }
    }
    int getFront()
    {
        if (this->empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    void print()
    {
        // if (this->empty())
        // {
        //     cout << "Queue is empty!" << endl;
        //     return;
        // }
        cout << "Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q(3);

    q.push(4);
    q.push(14);
    q.push(41);
    // q.push(4);
    q.print();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    cout << q.front << " " << q.rear << " " << endl;
    cout << "Front elem: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;

    // q.push(41);
    // q.print();
    // q.push(42);
    // q.print();
    // q.push(43);
    // q.print();

    return 0;
}