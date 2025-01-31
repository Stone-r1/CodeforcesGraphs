// Codeforces Problem: Maze
// https://codeforces.com/contest/377/problem/A

#include <iostream>
#include <unordered_map>
#include <cstring>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


char grid[501][501];
bool visited[501][501];

void dfs(int row, int column, int& k, int n, int m)
{
    if (k == 0) return;
    visited[row][column] = true;

    // directions
    int dirRow[] = {-1, 1, 0, 0};
    int dirCol[] = {0, 0, -1, 1};

    // try all 4 directions
    for (int i = 0; i < 4; i++)
    {
        int newR = row + dirRow[i];
        int newC = column + dirCol[i];

        // check conditions
        if (grid[newR][newC] == '.' && !visited[newR][newC]) dfs(newR, newC, k, n, m);
    }

    if (k > 0) 
    {
        grid[row][column] = 'X';
        k--;
    }    
}

void solve(int n, int m, int k)
{
    int row = 0, column = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            std::cin >> grid[i][j];

            if (grid[i][j] == '.')
            {
                row = i;
                column = j;
            }
        }
    }

    std::memset(visited, false, sizeof(visited));
    dfs(row, column, k, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) std::cout << grid[i][j];
        std::cout << '\n';
    }
}

int main()
{
    inout;
    int n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
}
