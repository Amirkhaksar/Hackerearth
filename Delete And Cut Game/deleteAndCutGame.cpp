/**
 * @file deleteAndCutGame.cpp
 * @author amir aghazadeh (cssu-ama)
 * @brief 
 * @version 0.1
 * @date 2022-07-22
 * @id 256
 * @language cpp
 * @questionLink https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/delete-and-cut-game-91969de1/
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 17, mod = 1e9 + 7;

struct E{
    int v, u;
    bool bl;
    int o(int x){
        return x == v ? u : v;
    }
}  e[maxn];
int n, m, sz[maxn], hi[maxn], h[maxn];
vector<E*> g[maxn];
bool mark[maxn];
void dfs(int v = 0, int p = -1){
    mark[v] = 1;
    sz[v] = 1;
    hi[v] = h[v];
    for(auto e : g[v]){
        int u = e -> o(v);
        if(u != p)
            if(!mark[u]){
                h[u] = h[v] + 1;
                dfs(u, v);
                sz[v] += sz[u];
                if(hi[u] == h[u])
                    e -> bl = 1;
                hi[v] = min(hi[v], hi[u]);
            }
            else
                hi[v] = min(hi[v], h[u]);
    }
}
int rev(int a){
    int ans = 1;
    for(int b = mod - 2; b; b >>= 1, a = (ll) a * a % mod)
        if(b & 1)
            ans = (ll) ans * a % mod;
    return ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> e[i].v >> e[i].u;
        e[i].v--, e[i].u--;
        g[e[i].v].push_back(&e[i]);
        g[e[i].u].push_back(&e[i]);
    }
    dfs();
    int a = 0, b = 0;
    for(int i = 0; i < m; i++)
        if(e[i].bl){
            int cmp = min(sz[e[i].v], sz[e[i].u]);
            if(n % 2 == 0 && cmp % 2 == 0)
                a++;
            else
                b++;
        }
    cout << (ll) a * rev(a + b) % mod << ' ' << (ll) b * rev(a + b) % mod << '\n';
}