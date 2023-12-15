#include <iostream>
#include <stack>
using namespace std;

void midValue(stack<int> &st, int pos, int &ans)
{
    // base case
    if (pos == 1)
    {
        ans = st.top();
        return;
    }

    pos--;
    int temp = st.top();
    st.pop();
    midValue(st, pos, ans);
    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
    int size = st.size();
    if (size == 0)
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    int pos = (size & 1) == 0 ? size / 2 : (size / 2) + 1;
    int ans = -1;
    midValue(st, pos, ans);
    return ans;
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    int ans = getMiddleElement(st);

    cout << "Mid element: " << ans << endl;

    return 0;
}