#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getNextMin(vector<int> &v)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (st.top() >= v[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(v[i]);
    }
    return ans;
}

void print(vector<int> &v)
{
    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v{2, 6, 8, 9, 3};

    vector<int> ans = getNextMin(v);

    cout << "Ans: ";
    print(ans);

    return 0;
}