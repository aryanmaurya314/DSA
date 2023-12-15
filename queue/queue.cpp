#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        int *arr = new int[size];
        this->size = size;
        this->front = -1; 
        this->rear = -1;
    }
    void push(int data)
    {
        if (this->rear == this->size)
        {
            cout << "Can't insert. Queue is full!" << endl;
            return;
        }

        if (this->empty())
        {
            this->front++;
        }
        this->rear++;
        this->arr[rear] = data;
    }
    bool empty()
    {
        return this->front == -1 && this->rear == -1;
    }
    int getSize()
    {
        return this->empty() ? 0 : rear - front + 1;
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Can't pop. Queue is empty!" << endl;
        }
        else
        {
            arr[this->front] = 0;
            this->front++;
            if (this->front == this->rear)
            {
                this->front = -1;
                this->rear = -1;
            }
        }
    }
    int getFront()
    {
        if (this->empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return this->arr[this->front];
    }
    void print()
    {
        cout << "Printing Queue: ";
        for (int i = 0; i < this->getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(4);

    q.push(4);
    q.push(41);
    q.push(12);
    q.print();
    cout << "Front: " << q.getFront() << endl;

    return 0;
}