#if !defined(STACK_ALGO)
#define STACK_ALGO
#include <stack>
#include <iostream>
using namespace std;

void insertSorted(stack<int> &st, int data)
{
    // base case
    if (st.empty() || st.top() <= data)
    {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, data);
    // backtrack
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();
    sortStack(st);
    // backtrack
    insertSorted(st, temp);
}

void printStack(stack<int> &st)
{
    if (st.empty())
    {
        cout << endl;
        return;
    }

    int temp = st.top();
    cout << temp << " ";
    st.pop();
    printStack(st);
    st.push(temp);
}

#endif // STACK_ALGO
