/*
Language: C++
ID: pikachu-and-champions-league-608a1d43
QLink: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/pikachu-and-champions-league-608a1d43/
Author: AmirZoyber
*/

#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <vector>

 
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, l, r) for (int i = l; i > r; i--)
#define sz(a) (int)a.size()


 
const int N = 500000;
const int inf = (int)1e9 + 1;
const int MOD = (int)1e9 + 7;

inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }

std::vector<int> g[N];
int height[N];
int in[N];
std::vector<std::pair<int, int> > order;
int sz[N];
 
int dfs(int u, int par, int h)
{
    in[u] = order.size();
    order.push_back({h, u});
    height[u] = h;
    for (int v : g[u])
        if (v != par)
        {
            sz[u] += dfs(v, u, h + 1);
            order.push_back({h, u});
        }
    return sz[u];
}
 
int log_2[N * 2];
std::pair<int, int> st[20][N * 2];
 
void build()
{
    int n = order.size();
    log_2[1] = 0;
    for (int i = 2; i <= n; i++)
        if (i >= (1 << (log_2[i - 1] + 1)))
            log_2[i] = log_2[i - 1] + 1;
        else
            log_2[i] = log_2[i - 1];
    int sz = 0;
    while ((1 << sz) <= n)
        sz++;
    for (int i = 0; i < n; i++)
        st[0][i] = order[i];
    for (int j = 1; j < sz; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
 
std::pair<int, int> get_ans(int l, int r)
{
    int len = log_2[r - l];
    return std::min(st[len][l], st[len][r - (1 << len)]);
}
 
int get_lca(int u, int v)
{
    u = in[u];
    v = in[v];
    if (u > v)
        std::swap(u, v);
    return get_ans(u, v + 1).second;
}
 
int get_dist(int u, int v)
{
    int lca = get_lca(u, v);
    return height[u] + height[v] - 2 * height[lca];
}
 
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.precision(20);
    std::cout << std::fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n, q;
    std::cin >> n >> q;
    rep(i, 0, n - 1)
    {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);
    build();
    while (q--)
    {
        int k;
        std::cin >> k;
        std::vector<int> a(k);
        rep(i, 0, k)
        {
            std::cin >> a[i];
            a[i]--;
        }
        int best = -1, v = -1;
        rep(i, 0, k)
        {
            int d = get_dist(a[0], a[i]);
            if (d > best)
            {
                best = d;
                v = a[i];
            }
        }
        best = -1;
        rep(i, 0, k)
            setmax(best, get_dist(v, a[i]));
        std::cout << best << "\n";
    }
    return 0;
} 