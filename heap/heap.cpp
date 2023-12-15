#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size, capacity;

    MaxHeap(int capacity)
    {
        this->arr = new int[capacity + 1]; // 1 based index array
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
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
        if (size == 0)
        {
            cout << "Heap underflow!" << endl;
            return -1;
        }
        // find first element to remove
        int index = 1;
        int answer = arr[index];
        arr[index] = arr[size];
        size--;

        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            int largestIndex = index;

            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }

            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }

            if (largestIndex == index)
            {
                break;
            }

            swap(arr[largestIndex], arr[index]);
            index = largestIndex;
        }

        return answer;
    }

    void printHeap()
    {
        cout << "Printing heap: ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    MaxHeap h(6);

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    // h.insert(9);
    // h.insert(12);

    h.printHeap();

    cout << "Removed element: " << h.remove() << endl;
    h.insert(12);
    h.printHeap();

    return 0;
}