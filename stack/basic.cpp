#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<int> st;

    // 1. add elements
    st.push(3);
    // st.push(4);
    // st.push(5);
    // 2. remove elements
    st.pop();
    // 3. get current size
    cout << st.size() << endl;
    // 4. check empty
    cout << st.empty() << endl;
    // 5. get top element
    cout << st.top() << endl;

    return 0;
}