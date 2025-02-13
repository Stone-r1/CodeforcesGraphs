// Codeforces Problem : Remove Exactly Two
// https://codeforces.com/problemset/problem/2063/C

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;

std::vector<std::vector<int>> graph;

void solve()
{
    int n, u, v;
    std::cin >> n;

    graph.clear();
    graph.resize(n+1);

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::multiset<int> set;
    for (int i = 1; i <= n; i++) 
    {
        set.insert(graph[i].size());
        set.insert(graph[i].size()-1);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int neighbor : graph[i]) set.erase(set.find(graph[neighbor].size()));
        set.erase(set.find(graph[i].size()));
        set.erase(set.find(graph[i].size()-1));

        answer = std::max(answer, (int)graph[i].size() + *set.rbegin()-1);
        for (int neighbor : graph[i]) set.insert(graph[neighbor].size());
        set.insert(graph[i].size());
        set.insert(graph[i].size()-1);
    }

    std::cout << answer << '\n';
}

int main()
{
    inout;
    int t;
    std::cin >> t;
    while (t--) solve();
}

