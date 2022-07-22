#include <bits/stdc++.h>

using namespace std;

/**
 * id: 215
 * author: amir aghazadeh (cssu-ama)
 * question link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/coloring-the-tree-7e8a557a/
 * language: cpp
 */

#define int int64_t

#define vc vector

#define mk make_pair

#define pb push_back

#define gh cout << endl;

#define PII pair<int,int>

#define all(x) x.begin(),x.end()

string yes="YES\n",no="NO\n",sp=" ";

#define fo(i,k,n) for(int i=k;i<=n;i++)

#define rfo(i,n,k) for(int i=n;i>=k;--i)

#define W(x) cout<<'['<<(#x)<<" : "<<(x)<<"]"<<sp;

#define I(x,y) W(x);W(y);

#define Display(A,k,n) cout << (#A) << " : ";for(int i=k;i<=n;i++){cout << A[i] << sp;}cout << endl;

const int mod = 1e9+7, Z = 2e5+5, Infinite = 1e18+5;

void solve();

 

int32_t main(){

ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 cout<<fixed<<setprecision(25);

 int Test=1;//cin >> Test;

 fo(T,1,Test)solve();

 return 0;

}

 

vc<int> G[Z], Degree(Z,0);

map<int,int> Terminal;

int N, K, u, v, x;

 

void solve(){

 cin >> N >> K;

 fo(i,1,N-1){

   cin >> u >> v;

   G[u].pb(v);

   G[v].pb(u);

   Degree[v]++;

   Degree[u]++;

 }

 

 fo(i,1,K){

   cin >> x;

   Terminal[x] = 1;

 }

 queue<int> Q;

 fo(i,1,N){

   if(Degree[i]==1 && Terminal[i]==0)Q.push(i);

 }

 

 while(!Q.empty()){

   int Node = Q.front();

   Degree[Node]--;

   Q.pop();

   fo(i,0,G[Node].size()-1){

     int H = G[Node][i];

     if(Degree[H]>0)Degree[H]--;    

     if(Degree[H]==1 && Terminal[H]==0)Q.push(H);

   }

 }

 int Ans = 0;

 fo(i,1,N){

   if(Degree[i]>0)Ans++;

 }

 cout << Ans << endl;

}