// Codeforces Problem: Minimum Maximum distances
// https://codeforces.com/contest/1881/problem/F

#include <iostream>
#include <vector>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


void bfs(int start, std::vector<std::vector<int>>& graph, std::vector<int>& distances)
{
    std::vector<int> v;
    std::fill(distances.begin(), distances.end(), -1);
    distances[start] = 0;
    v.push_back(start);

    int front = 0;
    while (front < v.size())
    {
        int node = v[front];
        front++;

        for (int neighbor : graph[node])
        {
            if (distances[neighbor] == -1) // unvisited
            {
                distances[neighbor] = distances[node] + 1;
                v.push_back(neighbor);
            }
        }
    }
}

int findFarthest(int max, int farthest, std::vector<bool>& marked, std::vector<int>& distances, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (marked[i] && distances[i] > max)
        {
            max = distances[i];
            farthest = i;
        }
    } 

    return farthest;
}

void solve()
{
    int n, k, u, v, a;
    std::cin >> n >> k;
     
    std::vector<int> distances(n);
    std::vector<std::vector<int>> graph(n);

    std::vector<bool> marked(n, false);
    for (int i = 0; i < k; i++) 
    {
        std::cin >> a;
        a--;
        marked[a] = true;
    }

    for (int i = 1; i < n; i++)
    {
        std::cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (k == 1) { std::cout << 0 << '\n'; return; } 

    bfs(0, graph, distances);
    int farthest1 = findFarthest(-1, -1, marked, distances, n);
    

    bfs(farthest1, graph, distances);
    int farthest2 = findFarthest(-1, -1, marked, distances, n);

    std::vector<int> distFirst(n), distSecond(n);
    bfs(farthest1, graph, distFirst);
    bfs(farthest2, graph, distSecond);

    int ans = n;
    for (int i = 0; i < n; i++) ans = std::min(ans, std::max(distFirst[i], distSecond[i]));
    std::cout << ans << '\n'; 
}

int main()
{
    inout;
    int t;
    std::cin >> t;

    while (t--) solve();
}
