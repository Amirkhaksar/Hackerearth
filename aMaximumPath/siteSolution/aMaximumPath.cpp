//Language: cpp
//ID: 206
//Qlink: https://www.hackerearth.com/problem/algorithm/path-maximum-bb1a923a/
//Author: hakerErth site solution

#include<bits/stdc++.h>
#define ll long long int
#define N 500005
#define log 25
using namespace std;
int n, q;
int a[N];
vector<int>adjacent[N];
int par[N];

int level[N];
int lca[N][log];
int maxWeight[N][log];

void dfs(int u, int p, int h){
    lca[u][0] = p;

    level[u] = h;
    if(p != -1){
        maxWeight[u][0] = max(a[u], a[p]);
    }

    for(int i = 1 ; i < log ; i++){
        if(lca[u][i-1] != -1){
            lca[u][i] = lca[lca[u][i-1]][i-1];
            maxWeight[u][i] = max(maxWeight[u][i-1], maxWeight[lca[u][i-1]][i-1]);
        }
    }

    for(int i = 0 ; i < adjacent[u].size() ; i++){
        int v = adjacent[u][i];
        if(v != p){
            dfs(v, u, h + 1);
        }
    }
}

int calculate(int u, int v){
    int ans = max(a[u], a[v]);
    
    if(level[u] > level[v]) swap(u,v);

    for(int i = log - 1 ; i >= 0 ; i--){
        if(lca[v][i] != -1 and level[lca[v][i]] >= level[u]){
            ans = max(ans, maxWeight[v][i]);
            v = lca[v][i];
        }
    }

    if(v == u){
        return ans;
    }
    else{
        for(int i = log - 1 ; i >= 0 ; i--){
            if(lca[v][i] != lca[u][i]){
                ans = max(ans, max(maxWeight[v][i], maxWeight[u][i]));
                v = lca[v][i];
                u = lca[u][i];
            }
        }
        ans = max(ans, max(maxWeight[v][0], maxWeight[u][0]));
    }

    return ans;
}

void solve(){
    cin >> n >> q;
    assert(1 <= n and n <= 500000);
    assert(1 <= q and q <= 500000);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < log ; j++){
            lca[i][j] = -1;
            maxWeight[i][j] = INT_MIN;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        assert(1 <= a[i] and a[i] <= 1000000000);
    }

    for(int i = 1 ; i <= n - 1 ; i++){
        int u, v;
        cin >> u >> v;
        assert(1 <= u and u <= n);
        assert(1 <= v and v <= n);
        assert(u != v);
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    dfs(1, -1, 0);

    while(q--){
        int u, v;
        cin >> u >> v;
        assert(1 <= u and u <= n);
        assert(1 <= v and v <= n);
        cout << calculate(u,v) << endl;
    }
}

int main(){
    solve();
}