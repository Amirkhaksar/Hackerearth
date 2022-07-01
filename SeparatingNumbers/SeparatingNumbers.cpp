/*Language: cpp
ID: 6fe976a9
QLink:www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define lli long long int
#define mxn 300010
 
map<int, int> m[mxn];
int par[mxn];
 
int find(int a) {
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}

lli uni(int a, int b){
    lli sum = 0;
    a = find(a);
    b = find(b);
 
    if(m[a].size() < m[b].size()) swap(a, b);
    
    for(pair<int,int> it: m[b]){
        if(m[a].find(it.first) == m[a].end())
            m[a][it.first] = it.second;
        else {
            sum += m[a][it.first] * 1LL * it.second;
            m[a][it.first] += it.second;
        }
    }
    par[b] = a;
    return sum;
}
 
void source(){
    int n, i, k, x, y;
 
    cin >> n;
    vector<int> rem(n-1);
    vector<lli> ans;
    vector<pair<int, int>> a;
 
    for(i = 1; i <= n; i++) par[i] = i;
    for(i = 1; i < n; i++){
        cin >> x >> y;
        a.push_back({x, y});
    }
    for(i = 1; i <= n; i++){
        cin >> x;
        m[i][x] = 1;
    }
    for(i = 0; i < n - 1; i++) cin >> rem[i];
 
    reverse(rem.begin(), rem.end());
 
    for(auto it: rem){
        x = a[it - 1].first;
        y = a[it - 1].second;
 
        ans.push_back(uni(x, y));
    }
    reverse(ans.begin(), ans.end());
 
    for(auto it: ans) cout << it << endl;

    return ;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    source();

    return 0;
}