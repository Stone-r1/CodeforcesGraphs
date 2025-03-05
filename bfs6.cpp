// Codeforces Problem : Party
// https://codeforces.com/contest/115/problem/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 998244353;
const ll MAX = 1e18;


std::vector<std::vector<int>> graph;
std::vector<int> depth, roots;

void bfs(int start)
{
    std::queue<int> q;
    q.push(start);
    depth[start] = 1;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node])
        {
            if (depth[neighbor] == -1)
            {
                depth[neighbor] = depth[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

void solve()
{
    int n, a;
    std::cin >> n;
    
    graph.assign(n+1, std::vector<int>());
    depth.assign(n+1, -1);
    
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a;
        if (a == -1) {roots.push_back(i); continue;}
        graph[a].push_back(i);
    }
    
    for (int i : roots) if (depth[i] == -1) bfs(i);
    std::cout << *std::max_element(depth.begin(), depth.end());
    
}

int main()
{
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
