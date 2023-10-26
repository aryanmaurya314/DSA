// maze: rows = m | cols = n | i = currRow | j = currCol
// Q1: Help a rat that is at (0,0) to reach its home at (m - 1, n - 1).
// TC = O(4^m*n) | SC = O(m*n)
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
char direction[4] = {'D', 'R', 'L', 'U'};

bool isSafe(vector<vector<bool>> &maze, vector<vector<bool>> &visited, int i, int j)
{
    if ((i >= 0 && i < maze.size()) && (j >= 0 && j < maze[0].size()) && (maze[i][j] == 1) && (visited[i][j] == 0))
    {
        return true;
    }

    return false;
}

void findPaths(vector<vector<bool>> &maze, vector<vector<bool>> &visited, int i, int j, vector<string> &paths, string path)
{
    // base case
    if (i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        paths.push_back(path);
        return;
    }

    // find paths
    /**
    // D: (i + 1, j)
    if (isSafe(maze, visited, i + 1, j))
    {
        // mark visited as true
        visited[i + 1][j] = 1;
        // move down recursively
        findPaths(maze, visited, i + 1, j, paths, path + 'D');
        // mark visited as false while backtracking
        visited[i + 1][j] = 0;
    }

    // R: (i, j + 1)
    if (isSafe(maze, visited, i, j + 1))
    {
        // mark visited as true
        visited[i][j + 1] = 1;
        // move down recursively
        findPaths(maze, visited, i, j + 1, paths, path + 'R');
        // mark visited as false while backtracking
        visited[i][j + 1] = 0;
    }

    // L: (i, j - 1)
    if (isSafe(maze, visited, i, j - 1))
    {
        // mark visited as true
        visited[i][j - 1] = 1;
        // move down recursively
        findPaths(maze, visited, i, j - 1, paths, path + 'L');
        // mark visited as false while backtracking
        visited[i][j - 1] = 0;
    }

    // U: (i - 1, j)
    if (isSafe(maze, visited, i - 1, j))
    {
        // mark visited as true
        visited[i - 1][j] = 1;
        // move down recursively
        findPaths(maze, visited, i - 1, j, paths, path + 'U');
        // mark visited as false while backtracking
        visited[i - 1][j] = 0;
    }
    */
    // improve code quality of movement
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isSafe(maze, visited, x, y))
        {
            // mark visited as true
            visited[x][y] = 1;
            // move down recursively
            findPaths(maze, visited, x, y, paths, path + direction[k]);
            // mark visited as false while backtracking
            visited[x][y] = 0;
        }
    }
}

vector<string> solveMaze(vector<vector<bool>> &maze)
{
    vector<string> paths;
    // if rat is not available at (0,0)
    if (maze[0][0] == 0)
    {
        return paths;
    }
    string path = "";
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    visited[0][0] = 1;
    int i = 0, j = 0;

    findPaths(maze, visited, i, j, paths, path);

    return paths;
}

int main()
{
    vector<vector<bool>> maze = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};

    vector<string> paths = solveMaze(maze);

    if (paths.size())
    {
        for (string path : paths)
        {
            cout << path << endl;
        }
    }
    else
    {
        cout << "No path found!" << endl;
    }

    return 0;
}