// TC = O(n^2)
#include <iostream>
#include <stack>
#include "stack_algo.h"
using namespace std;

void insertAtBottom(stack<int> &st, int data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(8);
    printStack(st);

    reverseStack(st);
    printStack(st);

    return 0;
}