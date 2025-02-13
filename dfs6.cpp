// Codeforces Problem : Ring Road
// https://codeforces.com/contest/24/problem/A

#include <iostream>
#include <vector>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


std::vector<std::vector<std::pair<int, int>>> graph;

int dfs(int n)
{
    int min = 1e9;
    for (auto [path, cost] : graph[0])
    {
        int x = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (auto [b, c] : graph[x]) if (b != path) {path = b; sum += c; break;}
            std::swap(path, x);
        }
        min = std::min(min, sum);
    } 
    return min;
}

void solve(int n)
{
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c;
        b--; a--;
        graph[a].push_back({b, 0}); // already given direction
        graph[b].push_back({a, c});
    }

    int min = dfs(n);
    std::cout << min << '\n';
}

int main()
{
    inout;
    int n;
    std::cin >> n;

    graph.resize(n);
    solve(n);
}
