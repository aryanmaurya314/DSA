// TC = O(9^(m * n)) | SC = O(m * n)
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int curr_row, int curr_col, char val)
{
    for (int i = 0; i < 9; i++)
    {
        // rowCheck
        if (board[curr_row][i] == val)
        {
            return false;
        }
        // colCheck
        if (board[i][curr_col] == val)
        {
            return false;
        }
        // 3 * 3 board check
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == val)
        {
            return false;
        }
    }
    // val is safe
    return true;
}

// this function returns true or false, on the basis of soluton found
bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char val = '1'; val <= '9'; val++)
                {
                    if (isSafe(board, i, j, val))
                    {
                        board[i][j] = val;
                        bool isSolutionFound = solveSudoku(board);
                        if (isSolutionFound)
                        {
                            return true;
                        }
                        // backtracking if solution not found
                        board[i][j] = '.';
                    }
                }
                // if 1 - 9 value se solution nhi mila to peeche galti
                // go back and return false matlab solution ni mila
                return false;
            }
        }
    }
    // all cell are filled now
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}