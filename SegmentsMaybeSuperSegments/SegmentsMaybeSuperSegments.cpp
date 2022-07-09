/*
Language: C++
ID: segments-maybe-super-segments-8cc3f9ed
QLink: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/segments-maybe-super-segments-8cc3f9ed/
Author: AmirZoyber
*/

#include <bits/stdc++.h>

const int N=2e5+7, M=13+7;
const int MOD=111539786;
const int oo=1e9+1e5+7;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, ll> ii;
typedef std::pair<int, ii> i3;


///////////////////////////////////////////////
int n, m, k, t;
 
ll p[N];
int dsu[N];
 
int root(int u) {
    int k=dsu[u];
    if(k<0) return u;
    dsu[u]=root(k);
    p[u]+=p[k];
    return dsu[u];
}
 
bool join(int u, int v, int cost) {
    int x=root(u), y=root(v); if(x==y) return 0;
    if(dsu[x]>dsu[y]) std::swap(x, y), std::swap(u, v), cost*=-1;

 
    p[y] = p[u] + cost - p[v];
 
    dsu[x]+=dsu[y], dsu[y]=x;
    return 1;
}
 
signed main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(dsu, -1, sizeof(int)*(n+7));
        memset(p, 0, sizeof(ll)*(n+7));
 
        int l, r, v;
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d", &l, &r, &v);
            join(l, r+1, v);
            //printf("%d %d | %d\n", l, r+1, v);
        }
 
        for(int i=1;i<=k;i++) {
            scanf("%d%d", &l, &r);
            if(root(l)!=root(r+1)) printf("-1");
            else printf("%lld", p[r+1]-p[l]);
            printf("\n");
        }
 
    }
 
    return 0;
}