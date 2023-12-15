// TC = O(n^2)
#include <iostream>
#include <stack>
#include "stack_algo.h"
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
    insertSorted(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(50);
    st.push(30);
    st.push(20);
    st.push(20);
    st.push(40);

    printStack(st);
    // insertSorted(st, 30);
    // printStack(st);
    sortStack(st);
    printStack(st);

    return 0;
}