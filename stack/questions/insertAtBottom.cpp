#include <iostream>
#include <stack>
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

void printStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    printStack(st);
    cout << temp << " ";
    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(22);
    st.push(31);

    printStack(st);
    cout << endl;
    insertAtBottom(st, 5);
    printStack(st);
    cout << endl;
    insertAtBottom(st, 15);
    printStack(st);
    cout << endl;

    return 0;
}