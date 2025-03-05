// Codeforces Problem : Tree Jumps
// https://codeforces.com/contest/2070/problem/D


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 998244353;
const ll MAX = 1e18;
// i think that's doable 

std::vector<std::vector<int>> graph;
std::vector<int> depth;


void bfs(int start)
{
    std::queue<int> q;
    q.push(start);
    depth[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (depth[neighbor] == -1) {depth[neighbor] = depth[node] + 1; q.push(neighbor);}
        }
    }
}

void solve()
{
   int n, a;
   std::cin >> n;

   graph.assign(n+1, std::vector<int>());
   depth.assign(n+1, -1);

   for (int i = 2; i <= n; i++)
   {
       std::cin >> a;
       graph[i].push_back(a);
       graph[a].push_back(i);
   }

   bfs(1);
   
   /* everything's correct so far
   for (int i = 0; i <= n; i++) std::cout << depth[i] << " ";
   std::cout << '\n';
   */

   ll max = *std::max_element(depth.begin(), depth.end());
   std::vector<ll> count(max+1, 0); 
   for (int i = 1; i <= n; i++) count[depth[i]]++;

   std::vector<ll> dp(max+1, 0);
   dp[max] = count[max] % MOD;
   for (int i = max-1; i >= 1; i--)
   {
       ll temp = (count[i] - 1 + MOD) % MOD;
       dp[i] = (count[i] + temp * dp[i+1]) % MOD;
   }

   std::cout << (1 + dp[1]) % MOD << '\n';
} 

int main()
{
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
