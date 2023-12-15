#include <iostream>
using namespace std;

struct MinHeap
{
    int *arr;
    int size, capacity;

    MinHeap(int size)
    {
        arr = new int[size];
        this->capacity = size;
        this->size = 0;
    }

    void insert(int val)
    {
        // check overflow condition
        if (size == capacity)
        {
            cout << "Heap overflow!" << endl;
            return;
        }

        arr[size] = val;
        int index = size;
        size++;
        // heapify
        while (index > 0)
        {
            int parentIndex = (index & 1) ? index / 2 : (index / 2) - 1;

            if (arr[parentIndex] > arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int remove()
    {
        // check underflow condition
        if (size == 0)
        {
            cout << "Heap underflow!" << endl;
            return -1;
        }

        int index = 0;
        int ans = arr[index];
        arr[index] = arr[size - 1];
        size--;

        while (index < size - 1)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int minIndex = index;

            if (left < size && arr[left] < arr[minIndex])
            {
                minIndex = left;
            }

            if (right < size && arr[right] < arr[minIndex])
            {
                minIndex = right;
            }

            if (minIndex == index)
            {
                break;
            }

            swap(arr[minIndex], arr[index]);
        }

        return ans;
    }

    void print()
    {
        cout << "Printing minheap: ";
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap h(6);

    h.insert(40);
    h.insert(20);
    h.insert(10);
    h.insert(60);
    h.insert(30);
    h.insert(50);
    // h.insert(70);
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    // cout << "Removed: " << h.remove() << endl;
    // h.print();

    return 0;
}