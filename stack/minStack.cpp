#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
private:
    vector<pair<int, int>> st;

public:
    void push(int data)
    {
        pair<int, int> p;
        p.first = data;
        p.second = st.empty() ? data : min(data, this->getMin());
        this->st.push_back(p);
    }

    void pop()
    {
        if (st.empty())
            throw invalid_argument("Stack underflow!");
        this->st.pop_back();
    }

    int top()
    {
        if (st.empty())
            throw invalid_argument("Stack underflow!");
        return st.back().first;
    }

    int getMin()
    {
        if (st.empty())
            throw invalid_argument("Stack underflow!");
        return st.back().second;
    }
};

int main()
{
    MinStack *st = new MinStack();

    cout << st->getMin() << endl;
    st->push(5);
    cout << "Top: " << st->top() << " Min: " << st->getMin() << endl;
    st->push(15);
    cout << "Top: " << st->top() << " Min: " << st->getMin() << endl;

    st->push(7);
    cout << "Top: " << st->top() << " Min: " << st->getMin() << endl;

    st->push(1);
    cout << "Top: " << st->top() << " Min: " << st->getMin() << endl;

    return 0;
}