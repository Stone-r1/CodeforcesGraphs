// Codeforces Problem: The Tag Game
// https://codeforces.com/contest/813/problem/C

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


std::vector<std::vector<int>> graph(200001);

void bfs(int start, std::vector<int>& distances)
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

int main()
{
    inout;
    int n, x, a, b;
    std::cin >> n >> x;

    for (int i = 1; i < n; i++)
    {
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> distancesA(n+1), distancesB(n+1);

    bfs(1, distancesA); 
    bfs(x, distancesB);

    /*
    for (int i = 1; i < n; i++) std::cout << distancesA[i] << " ";
    std::cout << '\n'; 
    for (int i = 1; i < n; i++) std::cout << distancesB[i] << " ";
    std::cout << '\n';
    */

    int total = 0;
    for (int i = 1; i <= n; i++) if (distancesA[i] > distancesB[i]) total = std::max(total, distancesA[i]);
    std::cout << total * 2 << '\n';
}
