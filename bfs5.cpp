// Codeforces Problem : King's Path
// https://codeforces.com/contest/242/problem/C

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
const ll MAX = 1e18;

int rowDir[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colDir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
std::unordered_map<ll, std::set<ll>> map;

// okay now this one is very nice problem.
void bfs(ll x0, ll y0, ll x1, ll y1)
{
    std::queue<std::tuple<ll, ll, ll>> q;
    q.push({x0, y0, 0});
    
    std::set<std::pair<ll, ll>> visited;
    visited.insert({x0, y0});
    
    while (!q.empty())
    {
        auto [r, c, d] = q.front();
        q.pop();
        
        if (r == x1 && c == y1) {std::cout << d; return;}
        for (int i = 0; i < 8; i++)
        {
            ll newR = r + rowDir[i], newC = c + colDir[i];
            if (map.find(newR) != map.end() && map[newR].find(newC) != map[newR].end())
            {
                if (visited.find({newR, newC}) == visited.end())
                {
                    visited.insert({newR, newC});
                    q.push({newR, newC, d + 1});
                }
            }
        }
    }
    std::cout << -1;
}

void solve()
{
    ll x0, y0, x1, y1, n, r, a, b;
    std::cin >> x0 >> y0 >> x1 >> y1 >> n;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> r >> a >> b;
        for (int j = a; j <= b; j++) map[r].insert(j);
    }
    
    bfs(x0, y0, x1, y1);
}

int main()
{
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
