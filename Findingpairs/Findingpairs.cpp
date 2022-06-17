/*Language: cpp
ID: 699bc085
QLink:www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-pairs-4-699bc085/
Author: @ellicoder */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int>g[N];
int depth[N];
vector<bool>vis(N, false);

void dfs(int source){
   vis[source] = true;
   for(auto child:g[source]){
       if(vis[child]==true) continue;
            depth[child] = depth[source] + 1;
       dfs(child);
   }
}

int main(){
   int n;
   cin >> n;
   for(int i = 0; i < n - 1; i++){
       int x, y;
       cin >> x >> y;
       g[x].push_back(y);
       g[y].push_back(x);
       }
       dfs(1);
   long long int sum = n;
   for(int i = 1; i <= n; i++)
       sum += depth[i];

    cout << sum;

}