// Codeforces Problem: Sakurako's Hobby
// https://codeforces.com/contest/2008/problem/D 

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> blacks;
std::string s;


void dfs(int node, std::vector<int>& components, int& blackCount)
{
    visited[node] = true;
    components.push_back(node);

    if (s[node-1] == '0') blackCount++;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor]) dfs(neighbor, components, blackCount);
    }
}

void solve()
{
    int n, v, ans = 0;
    std::cin >> n;

    graph.clear(), visited.clear(), blacks.clear();
    graph.resize(n+1);
    visited.resize(n+1, 0);
    blacks.resize(n+1, false);

    for (int u = 1; u <= n; u++)
    {
        std::cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::cin >> s;
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i])
        {
            std::vector<int> component;
            int blackCount = 0;

            dfs(i, component, blackCount);

            for (int node : component) blacks[node] = blackCount;
        }
    }

    for (int i = 1; i <= n; i++) std::cout << blacks[i] << " ";
    std::cout << '\n';
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
