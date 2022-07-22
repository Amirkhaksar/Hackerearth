#include<bits/stdc++.h>
using namespace std;

/**
 * id: 228
 * author: amir aghazadeh (cssu-ama)
 * question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimize-graph-weight-2fc2503b/
 * language: cpp
 * 
 */

int find(int w[], int x)
{
    if(w[x] == x)
        return x;
    return (w[x] = find(w, w[x]));
}
void dfs(vector<int> graph[], int vis[], int i, vector<int> &A, int &mn)
{
    assert(1 <= A[i] && A[i] <= 1e9);
    vis[i] = 1;
    mn = min(mn, A[i]);
    for(auto j : graph[i])
        if(!vis[j])
            dfs(graph, vis, j, A, mn);
        
}
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return (a[2] < b[2]);
}
long long solve (int N, int M, vector<int> A, vector<vector<int> > edges) {
    // Write your code here
    int vis[N+1] = {0};
    assert(1 <= N && N <= 1e5);
    assert(0 <= M && M <= 1e5);
    vector<int> graph[N+1];
    int i;
    sort(edges.begin(), edges.end(), cmp);
    int w[N+1] = {0}, sz[N+1] = {0};
    for(i=0;i<=N;i++)
        w[i] = i, sz[i] = 1;
    long long ans = 0;
    set<pair<int, int>> mp;
    for(i=0;i<M;i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        assert(mp.find({u, v}) == mp.end());
        assert(u != v);
        mp.insert({u, v});
        mp.insert({v, u});
        assert(1 <= wt && wt <= 1e9);
        int a = find(w, u);
        int b = find(w, v);
        if(a == b)
            continue;
        ans = ans + wt;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(sz[a] < sz[b])
            w[a] = b, sz[b]+=sz[a];
        else
            w[b] = a, sz[a]+=sz[b];
    }
    reverse(A.begin(), A.end());
    A.push_back(0);
    reverse(A.begin(), A.end());
    long long sum = 0;
    vector<int> vec;
    for(i=1;i<=N;i++)
        if(!vis[i])
        {
            int mn = 1e9;
            dfs(graph, vis, i, A, mn);
            vec.push_back(mn);
        }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    vec.pop_back();
    for(auto j : vec)
        sum+=j;
    return (sum + ans);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    assert(1 <= T && T <= 10);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }
        vector<vector<int> > edges(M, vector<int>(3));
        for (int i_edges = 0; i_edges < M; i_edges++)
        {
            for(int j_edges = 0; j_edges < 3; j_edges++)
            {
                cin >> edges[i_edges][j_edges];
            }
        }

        long long out_;
        out_ = solve(N, M, A, edges);
        cout << out_;
        cout << "\n";
    }
}