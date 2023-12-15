#include <iostream>
#include <vector>
using namespace std;

class LinkedList
{
public:
    int val;
    LinkedList *next;
    LinkedList *head;
    LinkedList *tail;
    int size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        next = NULL;
        size = 0;
    }

    LinkedList(int val)
    {
        this->val = val;
        next = NULL;
    }

    int get(int index)
    {
        if (index >= size)
            return -1;

        LinkedList *curr = head;

        while (index)
        {
            curr = curr->next;
            index--;
        }

        return curr->val;
    }

    void insertHead(int val)
    {
        LinkedList *newNode = new LinkedList(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertTail(int val)
    {
        LinkedList *newNode = new LinkedList(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {

            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool remove(int index)
    {
        if (index >= size)
            return false;
        LinkedList *curr = head;
        // remove at head
        if (index == 0)
        {
            head = head->next;
            curr->next = NULL;
            delete curr;
        }
        else if (index > 0 && index < size - 1)
        { // remove from middle index
            for (int i = 0; i < index - 1; i++)
            {
                curr = curr->next;
            }
            LinkedList *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else // remove at tail
        {
            while (curr->next->next)
            {
                curr = curr->next;
            }
            tail = curr;
            curr = curr->next;
            tail->next = NULL;
            delete curr;
        }
        size--;
        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;
        LinkedList *curr = head;
        while (curr)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};

void print(vector<int> v)
{
    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    LinkedList ll;

    /*
    ll.insertHead(4);
    ll.insertHead(3);
    ll.insertTail(5);
    ll.insertHead(2);
    ll.insertTail(6);
    cout << "Size: " << ll.size << endl;
    cout << "Values: ";
    print(ll.getValues());
    cout << "value at index: " << ll.get(6) << endl;
    cout << "Remove: " << ll.remove(2) << endl;
    cout << "Values: ";
    print(ll.getValues());
    */
    //    ["insertTail", 1, "insertTail", 2, "get", 1, "remove", 1, "insertTail", 2, "get", 1, "get", 0]
    // [null,null,2,true,null,2,1]

    ll.insertHead(1);
    // ll.insertTail(2);
    // cout << "value at index: " << ll.get(1) << endl;
    cout << "Remove: " << ll.remove(2) << endl;
    cout << "Remove: " << ll.remove(1) << endl;
    // ll.insertTail(2);
    // cout << "value at index: " << ll.get(1) << endl;
    // cout << "value at index: " << ll.get(0) << endl;

    return 0;
}