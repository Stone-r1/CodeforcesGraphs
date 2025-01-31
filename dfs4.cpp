// Codeforces Problem: Paint The Tree
// https://codeforces.com/contest/1975/problem/D

#include <iostream>
#include <vector>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;

std::vector<std::vector<int>> graph;
std::vector<int> depthV, parentV;
int max;


void dfs(int node, int parent)
{
    parentV[node] = parent;
    depthV[node] = depthV[parent] + 1;
    max = std::max(max, depthV[node]);

    for (int neighbor : graph[node])
    {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
    }
}

void solve()
{
    int n, a, b, u, v;
    std::cin >> n >> a >> b;

    graph.clear();
    graph.resize(n + 1);
    depthV.assign(n + 1, 0);
    parentV.assign(n + 1, 0);
    max = -1;

    for (int i = 1; i < n; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    depthV[0] = -1;
    dfs(1, 0);

    std::vector<int> pathA, pathB;
    while (a != b)
    {
        if (depthV[a] > depthV[b]) { pathA.push_back(a); a = parentV[a]; }
        else if (depthV[a] < depthV[b]) { pathB.push_back(b); b = parentV[b]; }
        else { pathA.push_back(a); pathB.push_back(b); a = parentV[a], b = parentV[b]; }
    }

    pathA.push_back(a);
    std::reverse(pathB.begin(), pathB.end());
    pathA.insert(pathA.end(), pathB.begin(), pathB.end());

    int middleNode = pathA[(pathA.size() - 1) / 2];
    max = -1;
    dfs(middleNode, 0);

    std::cout << 2 * (n - 1) - max + (pathA.size() - 1 - (pathA.size() - 1) / 2) << '\n';
}

int main()
{
    inout;
    int t;
    std::cin >> t;

    while (t--) solve();
}
