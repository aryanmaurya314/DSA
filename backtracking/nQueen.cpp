// TC = O(n^n) --> O(n!) | SC = O(n^2)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
/** brute force ==>> : TC = O(n) in isSafe
bool isSafe(vector<vector<char>> &board, int n, int row, int col)
{
    int i = row, j = col;

    // check current row
    while (j >= 0)
    {
        if (board[i][j--] == 'Q')
        {
            return false;
        }
    }
    j = col;
    // check top left diagonal
    while (i >= 0 && j >= 0)
    {
        if (board[i--][j--] == 'Q')
        {
            return false;
        }
    }
    i = row;
    j = col;
    // check bottom left diagonal
    while (i < n && j >= 0)
    {
        if (board[i++][j--] == 'Q')
        {
            return false;
        }
    }

    // place queen is safe at this cell
    return true;
}
void placeQueen(vector<vector<char>> &board, int n, int col)
{
    // base case
    if (col == n)
    {
        printSolution(board, n);
        return;
    }
    // solve 1 case rest will handle recursion:
    // try to place queen in each row
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, n, row, col))
        {
            // place the queen
            board[row][col] = 'Q';
            // place n - 1 queens in next cols using recursion
            placeQueen(board, n, col + 1);
            // backtracking
            board[row][col] = '-';
        }
    }
}
*/

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> topLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void placeQueen(vector<vector<char>> &board, int n, int col)
{
    // base case
    if (col == n)
    {
        printSolution(board, n);
        return;
    }

    // solve 1 case rest will handle recursion:
    // try to place queen in each row
    for (int row = 0; row < n; row++)
    {
        if (!((rowCheck[row]) || (topLeftDiagonalCheck[row - col]) || (bottomLeftDiagonalCheck[row + col])))
        {
            // place the queen
            board[row][col] = 'Q';
            // update checkMap
            rowCheck[row] = true;
            topLeftDiagonalCheck[row - col] = true;
            bottomLeftDiagonalCheck[row + col] = true;
            // place n - 1 queens in next cols using recursion
            placeQueen(board, n, col + 1);
            // backtracking
            board[row][col] = '-';
            // backtracking checkMap
            rowCheck[row] = false;
            topLeftDiagonalCheck[row - col] = false;
            bottomLeftDiagonalCheck[row + col] = false;
        }
    }
}

int main()
{
    int n = 11;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;

    placeQueen(board, n, col);

    return 0;
}