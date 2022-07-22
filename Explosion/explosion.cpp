#include <bits/stdc++.h>

using namespace std;

/**
 * id: 243
 * author: amir aghazadeh (cssu-ama)
 * question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/explosion-2-5f6ef62e/
 * language: cpp
 */

typedef long long ll;
const int MAX_N = 1e5 + 14;
vector<int> g[MAX_N];

int matching(int v = 0, int p = -1) {
    int need = 0;
    for (auto u : g[v]) {
        if (u == p)
            continue;
        int t = matching(u, v);
        if (t == -1)
            return -1;
        need += t == 0;
    }
    return need == 0 ? 0 : need == 1 ? 1 : -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(g, g + n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        cout << (matching() == 1 ? "UNSAFE\n" : "SAFE\n");
    }
}