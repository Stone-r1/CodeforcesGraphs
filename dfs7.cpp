#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 998244353;
const ll MAX = 1e18;


std::vector<std::vector<int>> graph;
std::vector<std::pair<int, int>> edges;
std::vector<int> state, order;
bool cycle = false;

void dfs(int node)
{
    state[node] = 1; // visited
    for (int neighbor : graph[node])
    {
        if (state[neighbor] == 0) {dfs(neighbor); if (cycle) return;}
        else if (state[neighbor] == 1) {cycle = true; return;}
    }
    state[node] = 2;
    order.push_back(node);
}

void solve()
{
    int n, m, t, u, v;
    std::cin >> n >> m;

    graph.assign(n+1, {});
    state.assign(n+1, 0);
    order.clear();
    edges.clear();

    for (int i = 0; i < m; i++)
    {
        std::cin >> t >> u >> v;
        if (t) {graph[u].push_back(v); continue;}
        edges.push_back({u, v});
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0) dfs(i);
        if (cycle) break;
    }

    if (cycle) {std::cout << "NO\n"; return;}

    std::reverse(order.begin(), order.end());
    std::vector<int> ind(n+1);
    for (int i = 0; i < n; i++) ind[order[i]] = i;

    std::vector<std::pair<int, int>> result;
    for (int i = 1; i <= n; i++) for (int v : graph[i]) result.push_back({i, v});

    for (auto edge : edges) 
    {
        int u = edge.first, v = edge.second;
        if (ind[u] < ind[v]) result.push_back({u, v});
        else result.push_back({v, u});
    }
    
    std::cout << "YES\n";
    for (auto edge : result) std::cout << edge.first << " " << edge.second << "\n"; 
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
