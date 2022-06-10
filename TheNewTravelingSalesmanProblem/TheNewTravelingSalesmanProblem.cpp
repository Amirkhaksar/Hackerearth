// Language: Python3.9
// ID: tzp-5a83020f
// QLink:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/approximate/tzp-5a83020f/
// Author: AmirZoyber

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int MAX_N = 1e5 + 121;
struct my{
    int to, c, g, index;
 
    my(){
 
    }
 
    my(int to1,int c1,int g1, int index1){
        to = to1;
        c = c1;
        g = g1;
        index = index1;
    }
 
};
 
int sqr(int x){
    return x*x;
}
 
int magic(int a,int b){
    return b;
}
 
bool cmp(my a,my b){
    return(magic(a.c, a.g) < magic(b.c, b.g));
}
vector<my> gr[MAX_N];
vector<int> result;
 
int need;
int used[MAX_N];
 
void dfs(int v,int lastEdge){
    if(lastEdge != 0){
        result.push_back(lastEdge);
    }
    used[v] = 1;
    --need;
    for(int i = 0; i < gr[v].size(); ++i){
        int to = gr[v][i].to;
        if(used[to])continue;
        dfs(to, gr[v][i].index);
        if(need)
            result.push_back(gr[v][i].index);
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    need = n;
    for(int i = 1; i <= m; ++i){
        int v, u, a, b;
        cin >> v >> u >> a >> b;
        gr[v].push_back(my(u, a, b, i));
        gr[u].push_back(my(v, a, b, i));
    }
 
    for(int i = 1; i <= n; ++i){
        assert((int)gr[i].size() > 0);
        sort(gr[i].begin(), gr[i].end(), cmp);
    }
 
    dfs(228, 0);
 
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << ' ';
 
    return 0;
}