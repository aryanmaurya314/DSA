// TC: K^2 * log(k) | SC: O(k^2)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info
{
    int value;
    int rowIndex;
    int colIndex;
};

struct Compare
{
    bool operator()(Info a, Info b)
    {
        return a.value > b.value;
    }
};

void merge(vector<vector<int>> &arr, int n, int k, vector<int> &ans)
{
    priority_queue< pair<char,int>, vector<pair<char,int>>, Compare> maxHeap;
    // create a min heap
    priority_queue<Info, vector<Info>, Compare> pq;

    // STEP 1: push first element of all the arrays to pq
    for (int row = 0; row < k; row++)
    {
        // create info object of first element
        Info first;
        first.value = arr[row][0];
        first.rowIndex = row;
        first.colIndex = 0;

        // put first to pq
        pq.push(first);
    }

    while (!pq.empty())
    {
        // get top element of pq which is minimum of all
        Info mini = pq.top();
        pq.pop();
        int minVal = mini.value;
        int rowIndex = mini.rowIndex;
        int colIndex = mini.colIndex;
        // push minVal to ans
        ans.push_back(minVal);

        colIndex = colIndex + 1;
        if (colIndex < n)
        {
            // push next minimum to pq
            Info newMini;
            newMini.value = arr[rowIndex][colIndex];
            newMini.rowIndex = rowIndex;
            newMini.colIndex = colIndex;

            pq.push(newMini);
        }
    }
}

int main()
{
    vector<vector<int>> arr{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int n = arr[0].size();
    int k = arr.size();

    vector<int> ans;

    merge(arr, n, k, ans);

    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}