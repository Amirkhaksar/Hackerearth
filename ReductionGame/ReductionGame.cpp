/*Language: cpp
ID: 56c3c092
QLink:www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/reduction-game-56c3c092/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(i = 0;i < n; i++)
typedef long long ll;
const int nn = 1e4+5;
vector<int>adj[nn];
int visited[nn];
vector<vector<int>>v;  
ll a[nn];
ll x = 0, c, d, n;
unordered_map<ll,ll>mp;

void dfs(int v){
    visited[v] = 1;
    for(int i = 0;i < 30; i++){
        ll w = a[v] ^ (1<<i);
        if(mp.count(w))
            if(!visited[mp[w]])
                dfs(mp[w]);
    }
}

void dfs1(int v){
    visited[v] = 1;
    for(int i = 0;i < n; i++){
        ll w = a[v] ^ (a[i]);
        if(__builtin_popcount(w) > 1)
            if(!visited[i])
                dfs1(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long i, j, l, m, y = 0, z = 0;
        fr(i,nn){
            visited[i]=0;
            adj[i].clear();
            a[i]=0;
        }
        mp.clear();
        cin >> n;
        cin >> c >> d;
        fr(i, n){
            cin >> a[i];
            mp[a[i]] = i;
        }
        if(c <= d){
            x = 0;
            z = 0;
            for(i = 0;i < n; i++){
                if(!visited[i]){
                    dfs(i);
                    x += 1;
                }
            }
            x -= 1;
            z = x * d + (n - 1 - x) * c;
        }
        
        else{
            x = 0;
            if(n > 100)
                z = (n - 1) * d;
            else {
                memset(visited,0,sizeof(visited));
                for(i = 0;i < n; i++){
                    if(!visited[i]){
                        dfs1(i);
                        x += 1;
                    }
                }
                x -= 1;
                z = 0;
                z = x * c + (n - 1 - x) * d;
            }
        }
        cout << z << "\n";
    }
}