// Codeforces Problem: Mad City
// https://codeforces.com/contest/1873/problem/H

#include <iostream>
#include <vector>
#include <string>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


int entry = -1;

bool dfs1(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int node, int parent)
{
    visited[node] = true;

    for (int i : graph[node])
    {
        if (!visited[i]) if (dfs1(graph, visited, i, node)) return true; 
        else if (i != parent) return true;
    }
    return false;
}

bool dfs2(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int node, int parent)
{
    visited[node] = true;
    for (int i : graph[node])
    {
        if (i != parent && visited[i]) { entry = i; return true; }
        else if (i != parent && !visited[i]) if (dfs2(graph, visited, i, node)) return true;
    }
    return false;
}

int dfs3(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int node)
{
    visited[node] = true;
    int distance = 1e9;

    for (int i : graph[node])
    {
        if (i == entry) return 1;
        if (!visited[i]) distance = std::min(distance, dfs3(graph, visited, i)+1);
    }
    return distance;
}

void solve()
{
    int n, M, V, u, v;
    std::cin >> n >> M >> V;

    std::vector<std::vector<int>> graph(n+1);
    std::vector<int> degree(n+1, 0);
    std::vector<bool> visited(n+1, false);

    for (int i = 0; i < n; i++)
    {
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if (M == V) { std::cout << "NO\n"; return; }

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) 
        {
            if (dfs1(graph, visited, i, -1)) { isCycle = true; break; };
        }
    }
    if (!isCycle) { std::cout << "NO\n"; return; }

    visited.assign(n+1, false);
    dfs2(graph, visited, V, -1);

    visited.assign(n+1, false);
    int distanceM = 1e9, distanceV = 0;
    if (entry == M) distanceM = 0;
    else distanceM = dfs3(graph, visited, M);

    visited.assign(n+1, false);
    if (entry != V) distanceV = dfs3(graph, visited, V);
    // =================================================

    if (distanceV < distanceM) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main()
{
    inout;
    int t;
    std::cin >> t;

    while (t--) solve();
}
