// Codeforces Problem : Dijkstra?
// https://codeforces.com/contest/20/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
 
#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 998244353;
const ll MAX = 1e18;


int n, m;
std::vector<std::vector<std::pair<int, int>>> graph;

void dijkstra(int start, int end) 
{
    std::vector<ll> dist(n+1, MAX);
    std::vector<int> parent(n+1, -1);
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) 
    {
        ll a = pq.top().first, b = pq.top().second;
        pq.pop();

        if (a <= dist[b]) 
        {
            for (auto [v, w] : graph[b]) 
            {
                if (dist[b] + w < dist[v]) 
                {
                    dist[v] = dist[b] + w;
                    parent[v] = b;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    if (dist[end] == MAX) {std::cout << "-1\n"; return;}

    std::vector<int> path;
    for (int v = end; v != -1; v = parent[v]) path.push_back(v);
    for (int i = path.size() - 1; i >= 0; i--) std::cout << path[i] << " ";
    std::cout << '\n';
}

void solve() 
{
    std::cin >> n >> m;
    graph.assign(n + 1, {});

    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1, n);
}

int main() 
{
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
