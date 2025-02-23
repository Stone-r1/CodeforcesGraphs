// Codeforces Problem : Forever Winter
// https://codeforces.com/contest/1829/problem/F

#include <iostream>
#include <vector>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAX = 1e18;


std::vector<int> degree;
std::vector<std::vector<int>> graph;

void solve()
{
    int n, m, u, v;
    std::cin >> n >> m;
    
    degree.clear();
    graph.clear();
    degree.resize(n+1, 0);
    graph.resize(n+1);
    
    for (int i = 0 ; i < m; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[v]++;
        degree[u]++;
    }
    
    int center = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (degree[i] > 1)
        {
            int count = 0;
            for (int neighbor : graph[i]) {if (degree[neighbor] > 1) count++;}
            if (count > 1) {center = i; break;}
        }
    }

    int y = 0, x = degree[center]; 
    for (int neighbor : graph[center]) if (degree[neighbor] > 1) {y = degree[neighbor] - 1; break;}
    
    std::cout << x << " " << y << '\n';
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
