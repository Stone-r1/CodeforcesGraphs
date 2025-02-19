// Codefoces Problem : Iris and Game on the Tree
// https://codeforces.com/problemset/problem/2006/A

#include <iostream>
#include <string>
#include <vector>

#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;


void solve()
{
    int n, u, v;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    std::string s;
    std::cin >> s;

    int leaf0 = 0, leaf1 = 0, leafNon = 0, innerNon = 0, ans = 0;
    for (int i = 1; i < n; i++) 
    {
        if (degree[i] == 1) {if (s[i] == '1') leaf1++; else if (s[i] == '0') leaf0++; else leafNon++;}
        else {if (s[i] == '?') innerNon++;}
    }

    if (s[0] != '?')
    {
        if (s[0] == '0') ans = leaf1 + (leafNon + 1) / 2;
        else ans = leaf0 + (leafNon + 1) / 2;
    }
    else
    {
        if (leaf1 != leaf0) ans = std::max(leaf0, leaf1) + leafNon / 2;
        else 
        {
            if (innerNon & 1) ans = leaf0 + (leafNon + 1) / 2;
            else ans = leaf1 + leafNon / 2;
        }
    }

    std::cout << ans << '\n';
}

int main()
{
    inout;
    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
