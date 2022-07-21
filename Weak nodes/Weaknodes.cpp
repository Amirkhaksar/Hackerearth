/*
#Language:C++
#ID:Weak nodes
#QLink:https://www.hackerearth.com/problem/algorithm/rhezo-and-super-tanks-a5a3a2f1/
#All Accepet
#Author:Amirkhaksar
*/

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

const int mx = 50005;
ll value[mx];
vector<int>adjacent[mx];
vector<int>weak;
bool visited[mx];
int disc[mx];
int low[mx];
int parent[mx];
int tim;

int prime[9] = { 2,3,5,7,11,13,17,19,23 };
bool ap[mx];

ll POWER(ll a, ll b, ll mod)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void dfs(int u)
{
    visited[u] = true;

    disc[u] = low[u] = ++tim;
    int child = 0;
    for (int i = 0; i < adjacent[u].size(); i++) {
        int v = adjacent[u][i];

        if (!visited[v])
        {
            child++;
            parent[v] = u;
            dfs(v);

            low[u] = min(low[u], low[v]);

            if (parent[u] != 0 && low[v] >= disc[u]) ap[u] = true;

            if (parent[u] == 0 && child > 1) ap[u] = true;
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    assert(1 <= N <= 50000 && 1 <= M <= 50000);

    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
        assert(1 <= value[i] <= 1000000000);
    }

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;

        assert(1 <= u <= N);
        assert(1 <= v <= N);

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) dfs(i);
    }

    for (int i = 1; i <= N; i++)
    {
        if (ap[i] == true) weak.push_back(i);
    }

    int size = weak.size();

    vector<int>elem;
    ll f[512] = { 0 };

    for (int i = 0; i < size; i++)
    {
        ll val = value[weak[i]];
        ll ans = 0;
        for (int j = 0; j < 9; j++)
        {
            int cnt = 0;
            while (val % prime[j] == 0)
            {
                cnt++;
                val /= prime[j];
            }

            if (cnt > 0)
            {
                ans |= (1 << j);
            }
        }

        f[ans]++;
        elem.push_back(ans);
    }

    for (int i = 0; i < 512; i++) {
        f[i] = (POWER(2, f[i], MOD) - 1 + MOD) % MOD;
    }

    ll dp[2][10000] = { 0 };
    ll c = 1, p = 0;

    for (int i = 0; i < 512; i++) {
        ll temp = f[i];
        for (int j = 0; j < 512; j++)
            dp[c][j] = dp[p][j];
        for (int j = 0; j < 512; j++) {
            dp[c][j | i] = (dp[c][j | i] + ((dp[p][j] * temp) % MOD)) % MOD;
        }
        dp[c][i] = (dp[c][i] + temp) % MOD;
        c = !c;p = !p;
    }

    cout << dp[p][511] << endl;
    return 0;

}