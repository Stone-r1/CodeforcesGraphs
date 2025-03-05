// Codeforces Problem : Copil Copac Draws Trees
// https://codeforces.com/contest/1831/problem/C


#include <iostream>
#include <vector>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAX = 1e18;


std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> a, b;

void dfs(int node, int parent)
{
    for (auto [neighbor, index] : graph[node])
    {
        if (neighbor != parent)
        {
            b[neighbor] = index; 
            a[neighbor] = a[node] + (index < b[node] ? 1 : 0);
            dfs(neighbor, node);
        }
    }
}

void solve()
{
    int n, u, v;
    std::cin >> n;
    
    graph.clear();
    graph.resize(n+1);
    a.assign(n+1, 0);
    b.assign(n+1, 0);
    b[1] = n; // root
    
    for (int i = 1 ; i < n; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    
    dfs(1, -1);
    std::cout << *std::max_element(a.begin(), a.end()) <<'\n';
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
