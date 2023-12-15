#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack st;

    st.push(2);
    st.push(22);
    cout << st.top() << endl;

    return 0;
}