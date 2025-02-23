// Codeforces Problem : The Lakes
// https://codeforces.com/contest/1829/problem/E

#include <iostream>
#include <vector>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAX = 1e18;


std::vector<std::vector<int>> grid;
std::vector<int> rowDir = {1, -1, 0, 0}, colDir = {0, 0, -1, 1};

ll bfs(int i, int j, ll count)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return count;
    
    count += grid[i][j];
    grid[i][j] = 0;
    
    for (int d = 0; d < 4; d++)
    {
        int newR = i + rowDir[d], newC = j + colDir[d];
        count = bfs(newR, newC, count);
    }
    
    return count;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    grid.clear();
    grid.assign(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) std::cin >> grid[i][j];
    
    ll max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0) max = std::max(max, bfs(i, j, 0));
        }
    }
    
    std::cout << max << '\n';
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
