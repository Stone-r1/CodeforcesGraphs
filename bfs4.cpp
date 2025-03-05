// Codeforces Problem : Police Stations
// https://codeforces.com/contest/796/problem/D


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
const ll MAX = 1e9;


std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> police, distances, parent, removable;
int n, k, d;


void bfs()
{
    std::queue<int> q;
    for (int i = 0; i < k; i++) {distances[police[i]] = 0;q.push(police[i]);}
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (auto [neighbor, i] : graph[node]) 
        {
            if (distances[neighbor] == MAX) 
            {
                distances[neighbor] = distances[node] + 1;
                parent[neighbor] = i;
                
                if (distances[neighbor] < d) q.push(neighbor);
            }
        }
    }
}

void solve()
{
    int u, v;
    std::cin >> n >> k >> d;
    police.resize(k);
    distances.assign(n, MAX);
    parent.assign(n, -1);
    graph.assign(n, {});
    for (int i = 0; i < k; i++) {std::cin >> police[i]; police[i]--;}
    
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> u >> v;
        u--; v--;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    
    bfs();
    
    /* working by far
    for (int i : parent) std::cout << i << " ";
    std::cout << '\n';
    */
    // essential roads
    std::vector<bool> used(n-1, false);
    for (int i = 0; i < n; i++) if (parent[i] != -1) used[parent[i]] = true;
    
    for (int i = 0; i < n-1; i++) if (!used[i]) removable.push_back(i+1);
    
    std::cout << removable.size() << '\n';
    for (int i : removable) std::cout << i << " ";
}

int main()
{
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
