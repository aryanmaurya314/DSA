#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<char> ch{'a', 'b'};

    for (char ch : ch)
    {
        cout << ch << " ";
    }

    return 0;
}