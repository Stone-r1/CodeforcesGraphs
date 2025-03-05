// Codeforces Problem : Rumor
// https://codeforces.com/contest/893/problem/C

#include <iostream>
#include <vector>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAX = 1e18;


std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> price;

ll dfs(int node)
{
    visited[node] = true;
    ll min = price[node];
    
    for (int neighbor : graph[node]) if (!visited[neighbor]) min = std::min(min, dfs(neighbor));
    return min;
}

void solve()
{
    int n, m, u, v;
    std::cin >> n >> m;
    
    graph.clear();
    graph.resize(n+1);
    visited.resize(n+1, false);
    price.resize(n+1);

    for (int i = 1; i <= n; i++) std::cin >> price[i];
    for (int i = 0; i < m; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    ll totalSum = 0;
    for (int i = 1; i <= n; i++) if (!visited[i]) totalSum += dfs(i);
    for (int i = 1; i <= n; i++) if (!visited[i]) totalSum += price[i];
    std::cout << totalSum << '\n';
} 

int main()
{
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
