/*
Language: C++
ID: separate-paths-2638c0fa
QLink: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/separate-paths-2638c0fa/
Author: AmirZoyber
*/

#include<bits/stdc++.h>


#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
 
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
 
 
typedef std::pair<int,int>   II;
typedef std::vector< II >      VII;
typedef std::vector<int>     VI;
typedef std::vector< VI >    VVI;
typedef long long int   LL;
const int N = 500 + 20;const int M = 1e5 + 10;

VI g[N];
VI tree[N],rg[N],bucket[N];
int pil[N],par[N],dom[N],dsu[N],upt[N];
int arr[N],rev[N],T;
LL ress;
int Find(int u,bool x=0)
{
    if(u==dsu[u])return x?-1:u;
    int v = Find(dsu[u],1);
    if(v<0)return u;
    if(pil[upt[dsu[u]]] < pil[upt[u]])
        upt[u] = upt[dsu[u]];
    dsu[u] = v;
    return upt[u];
}
void Union(int u,int v) {
    dsu[v]=u;
}
void dfs0(int u) {
    T++;arr[u]=T;rev[T]=u;
    upt[T]=T;pil[T]=T;dsu[T]=T;
    for(int i=0;i<SZ(g[u]);i++)
    {
        int w = g[u][i];
        if(!arr[w])dfs0(w),par[arr[w]]=arr[u];
        rg[arr[w]].PB(arr[u]);
    }
}
int dfs(int u,int p, int de = 0)
{
    int sm = 1;
    for (int w: tree[u])
        if (w^p) {
            int temp = dfs(w,u, de+1);
            if (u == 1)
                ress -= temp*(temp-1)/ 2;
            sm += temp;
        }
    return sm;
}
int inD[N];

// main
int main(){
    int te; std::cin >> te;
    while (te--) {
        int n,m;
        si(n);si(m);
        n++;
        for (int i = 0; i <= n; i++) {
            inD[i] = 0;
            g[i].clear();
            rg[i].clear();
            tree[i].clear();
            bucket[i].clear();
            pil[i] = par[i] = dom[i] = dsu[i] = upt[i] = arr[i] = rev[i] = T = 0;
        }
        for(int i=0;i<m;i++)
        {
            int u,v;si(u);si(v);
            u++, v++;
            g[u].PB(v);inD[v]++;
        }
        int cnt = 0;
        for (int i = 2; i <= n; i++){
            if (inD[i] == 0){
                g[1].push_back(i);cnt++;}}
        if (cnt == 0){std::cout << "0\n";}
        else{
            dfs0(1),n=T;
            for(int i=n;i>=1;i--){
                for(int j=0;j<SZ(rg[i]);j++){pil[i] = std::min(pil[i],pil[Find(rg[i][j])]);}
                if(i>1){bucket[pil[i]].PB(i);}
                for(int j=0;j<SZ(bucket[i]);j++){
                    int w = bucket[i][j];int v = Find(w);
                    if(pil[v]==i){dom[w]=i;}
                    else {dom[w] = v;}}
                if(i>1)Union(par[i],i);}
            for(int i=2;i<=n;i++){
                if(dom[i]!=pil[i])
                    dom[i]=dom[dom[i]];
                tree[rev[i]].PB(rev[dom[i]]);tree[rev[dom[i]]].PB(rev[i]);}
 
            ress = (n-1)*(n-2)/ 2;
            dfs(1,1);
            lldout(ress);}
    }
}