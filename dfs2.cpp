// Codeforces Problem: Cyclic Components
// https://codeforces.com/contest/977/problem/E

#include <iostream>
#include <vector>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;

std::vector<std::vector<int>> graph(1000001);
int degree[1000001];
bool visited[1000001];

bool dfs(int x)
{
    if (degree[x] != 2) return false;

    visited[x] = true;
    bool isCycle = (degree[x] == 2);

    for (int i = 0; i < graph[x].size(); i++) if (!visited[graph[x][i]]) isCycle = std::min(isCycle, dfs(graph[x][i]));  
    return isCycle;
}

int main()
{
    inout;
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v, u;
        std::cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
        degree[v]++;
        degree[u]++;
    }

    int total = 0;
    for (int i = 0; i <= n; i++) if (!visited[i]) total += dfs(i);
    std::cout << total << '\n';
}
