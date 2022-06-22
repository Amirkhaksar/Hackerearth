/*Language: cpp
ID: ca482e2a
QLink:www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/breaking-edges-march-circuits-ca482e2a/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define ffor(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;

const int N = 2e5 + 1;
vector<vector<int>> g;
ll subtree[N];
ll m[N];
vector<bool> visited(N, false);
int x[N];
int a[N][22];
int ans = 0;

void dfs(int u, int p) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) {
            dfs(v, u); 
            for (int i = 0; i < 22; i++)
                a[u][i] += a[v][i];
        }
    }

    int check = 0;
    for (int i = 0; i < 22; i++) {
        if (!((a[u][i] > 0 && x[i] - a[u][i] > 0)
            || (a[u][i] == 0 && x[i] == 0))) {
            check = 1;
            break;
        }
    }
    if (check== 0)
        ans++;
}
 
    
void quiet() {
    int n;
    cin >> n;
    g.resize(n + 1);
    ffor(i, 1, n)
    cin>>m[i];

    for (int i = 1; i <= n; i++) {
        int y = m[i];
        int k = 0;

        while (y != 0) {
            int p = y % 2;
            if (p == 1) {
                x[k]++;
                a[i][k]++;
            }
            y = y / 2;
            k++;
        }
    }

    int m = n - 1;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0); 
    cout << (ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t = 1;
    while (t--)  
        quiet();
    return 0;
}