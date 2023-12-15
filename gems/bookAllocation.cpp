#include <iostream>
using namespace std;

int totalPages(int pages[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pages[i];
    }
    return sum;
}

bool isPossibleSolution(int A[], int N, int M, int sol)
{
    int pageSum = 0;
    int count = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol)
        {
            return false;
        }
        if (pageSum + A[i] > sol)
        {
            // allocate to other student
            count++;
            if (count > M)
            {
                return false;
            }
            pageSum = A[i];
        }
        else
        {
            pageSum += A[i];
        }
    }

    return true;
}

int findPages(int A[], int N, int M)
{
    // code here
    int ans = -1;
    if (M > N)
    {
        return ans;
    }

    int start = 0;
    int end = totalPages(A, N); // totalPages
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (isPossibleSolution(A, N, M, mid))
        { // if possible solution
            ans = mid;
            end = mid - 1;
        }
        else
        { // if not possible solution
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int pages[] = {15, 17, 20};
    int books = sizeof(pages) / sizeof(pages[0]);
    int students = 4;

    int ans = findPages(pages, books, students);

    cout << "Answer: " << ans << endl;

    return 0;
}