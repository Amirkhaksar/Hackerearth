/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/operation-on-tree-ae14ee70/
	author: Amir Aghazadeh
	id: 142
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 14, L = 30;
int n, k, dp[N][L], sz[N];
ll ans;
vector<int> g[N];

void dfs(int v = 0, int p = -1) {
    sz[v] = 1;
    for (auto u : g[v])
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
            ll cur = 0;
            for (int i = 0; i < L; ++i)
                if (k >> i & 1) {
                    cur += ll(sz[u] - dp[u][i] * 2) * (1 << i);
                    dp[v][i] += dp[u][i];
                }
            ans = max(ans, cur);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> k;
        fill(g, g + n, vector<int>());
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s += x;
            for (int j = 0; j < L; ++j)
                dp[i][j] = x >> j & 1;
        }
        for (int i = 0; i < n - 1; ++i) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        dfs();
        for (int u = 0; u < n; ++u) {
            ll cur = 0;
            for (int i = 0; i < L; ++i)
                if (k >> i & 1)
                    cur += ll(sz[0] - sz[u] - (dp[0][i] - dp[u][i]) * 2) * (1 << i);
            ans = max(ans, cur);
        }
        cout << ans + s << '\n';
    }
}
?

