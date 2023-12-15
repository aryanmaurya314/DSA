#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int capacity;
    int index;

public:
    DynamicArray(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        index = -1;
    }

    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n)
    {
        arr[i] = n;
    }

    void pushback(int n)
    {
        if (this->getSize() != capacity)
        {
            index++;
        }
        else
        {
            this->resize();
            index++;
        }
        arr[index] = n;
    }

    int popback()
    {
        int temp = arr[index];
        arr[index] = 0;
        index--;
        return temp;
    }

    void resize()
    {
        int *newArr = new int[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        arr = newArr;
        capacity = 2 * capacity;
    }

    int getSize()
    {
        return index + 1;
    }

    int getCapacity()
    {
        return capacity;
    }
};

int main()
{

    DynamicArray arr(3);

    cout << "Capacity: " << arr.getCapacity() << endl;
    cout << "Size: " << arr.getSize() << endl;
    arr.pushback(1);
    arr.pushback(2);
    cout << "Capacity: " << arr.getCapacity() << endl;
    cout << "Size: " << arr.getSize() << endl;
    arr.pushback(3);
    // arr.set(1, 4);
    cout << arr.get(1) << endl;
    arr.pushback(4);
    arr.resize();
    arr.popback();
    cout << "Capacity: " << arr.getCapacity() << endl;
    cout << "Size: " << arr.getSize() << endl;

    return 0;
}