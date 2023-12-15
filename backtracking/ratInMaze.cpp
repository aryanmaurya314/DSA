// TC = O(4^(m * n)) | SC = O(m * n) | if m = row, n = col

#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char direction[4] = {'D', 'L', 'R', 'U'};

bool isSafe(vector<vector<bool>> &m, int n, int i, int j, vector<vector<bool>> &visited)
{
    if (((i >= 0 && i < n) && (j >= 0 && j < n)) && (m[i][j] == 1) && (visited[i][j] == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void findPath(vector<vector<bool>> &m, int n, int i, int j, vector<vector<bool>> &visited, vector<string> &paths, string path)
{
    // base case
    if (i == n - 1 && j == n - 1)
    {
        paths.push_back(path);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        char dir = direction[k];
        if (isSafe(m, n, newX, newY, visited))
        {
            visited[newX][newY] = true;
            findPath(m, n, newX, newY, visited, paths, path + dir);
            // backtracking
            visited[newX][newY] = false;
        }
    }
}

void findPathBruteForce(vector<vector<bool>> &m, int n, int i, int j, vector<vector<bool>> &visited, vector<string> &paths, string path)
{
    // base case
    if (i == n - 1 && j == n - 1)
    {
        paths.push_back(path);
        return;
    }

    // DOWN --> (i + 1, j)
    if (isSafe(m, n, i + 1, j, visited))
    {
        visited[i + 1][j] = true;
        findPath(m, n, i + 1, j, visited, paths, path + 'D');
        // backtracking
        visited[i + 1][j] = false;
    }

    // LEFT --> (i, j - 1)
    if (isSafe(m, n, i, j - 1, visited))
    {
        visited[i][j - 1] = true;
        findPath(m, n, i, j - 1, visited, paths, path + 'L');
        // backtracking
        visited[i][j - 1] = false;
    }

    // RIGHT --> (i, j + 1)
    if (isSafe(m, n, i, j + 1, visited))
    {
        visited[i][j + 1] = true;
        findPath(m, n, i, j + 1, visited, paths, path + 'R');
        // backtracking
        visited[i][j + 1] = false;
    }

    // UP --> (i - 1, j)
    if (isSafe(m, n, i - 1, j, visited))
    {
        visited[i - 1][j] = true;
        findPath(m, n, i - 1, j, visited, paths, path + 'U');
        // backtracking
        visited[i - 1][j] = false;
    }
}

vector<string> solveMaze(vector<vector<bool>> &m, int n)
{
    vector<string> paths;
    string path = "";

    if (m[0][0] == 0)
    {
        return paths;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    findPath(m, n, 0, 0, visited, paths, path);

    return paths;
}

int main()
{
    vector<vector<bool>> maze = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}};

    int n = maze.size();

    vector<string> paths = solveMaze(maze, n);
    if (paths.size() == 0)
    {
        cout << "No paths found!" << endl;
    }
    else
    {
        for (string path : paths)
        {
            cout << path << " " << endl;
        }
    }

    return 0;
}