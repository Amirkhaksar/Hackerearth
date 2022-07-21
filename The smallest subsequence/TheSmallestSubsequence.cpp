/*
#Language:C++
#ID:The smallest subsequence
#QLink:https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/smallest-subsequence-2-02601ef9/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 14;
vector<int> g[N];
vector<int> pr[N];
int d[N], par[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int p = 2; p < N; ++p)
        if (pr[p].empty())
            for (int i = p; i < N; i += p)
                if (pr[i].size() < 2)
                    pr[i].push_back(p);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (int(sqrt(x)) * int(sqrt(x)) == x)
            return cout << 1, 0;
        if (pr[x].size() == 2) {
            g[pr[x][0]].push_back(pr[x][1]);
            g[pr[x][1]].push_back(pr[x][0]);
        }
        else if (pr[x].size() == 1) {
            g[pr[x][0]].push_back(1);
            g[1].push_back(pr[x][0]);
        }
    }
    int ans = INT_MAX;
    for (int p = 2; p * p < N; ++p)
        if (pr[p] == vector{ p }) {
            memset(d, 63, sizeof d);
            queue<int> q({ p });
            d[p] = 0;
            par[p] = -1;
            if (count(g[p].begin(), g[p].end(), par[p]) > 1)
                return cout << 2, 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto u : g[v])
                    if (d[u] > d[v] + 1) {
                        par[u] = v;
                        d[u] = d[v] + 1;
                        q.push(u);
                    }
                    else if (u != par[v])
                        ans = min(ans, d[v] + d[u] + 1);
            }
        }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}