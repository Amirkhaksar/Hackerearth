/**
 * @file aVertexSet.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-06-04
 * @lan cpp
 * @id 195
 * @Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/vertex-set-90a5e5a1/
 * 
 */

// A VERTEX SET
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n + 1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

vector<ll> F(1e5 + 5, 0);

// this dfs function stores the max node value of that substree in that currr node

ll dfs(ll v, ll p, vector<ll> adj[])
{
	ll mx = F[v];
	for(auto u : adj[v])
	{
		if(u == p) continue;
		ll a = dfs(u, v, adj);
		mx = max(mx, a);
	}
	F[v] = mx;
	return mx;
}

vector<ll> dp(1e5 + 5, 0);

// this dfs function performs DP on the subtree to approach ans

ll dfs1(ll v, ll p, vector<ll> adj[])
{
	ll x = 0, y = 0;

	// x stores the sum of values of children nodes
	// y stores the sum of values of grand children nodes

	for(auto u : adj[v])
	{
		if(u == p) continue;
		x += dfs1(u, v, adj);
		for(auto gc : adj[u])
		{
			if(gc == v) continue;
			y += dp[gc];
		}
	}

	// current node maxm value would be either choosing that node or eliminating that node

	dp[v] = max(dp[v] + y, x);
	return dp[v];
}

signed main()
{
    FIO;

	ll tests;
	cin >> tests;
	while(tests--)
	{
		ll n;  // no of nodes
		cin >> n;
		// adjacency list
		vector<ll> adj[n + 1];

		for(ll i = 1; i < n; i++)
		{
			ll a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// values of nodes stored in F
		for(ll i = 1; i <= n; i++) cin >> F[i];

		// calls dfs function to find the maxm node value in that subtree
		dfs(1, -1, adj);

		// initialise current (base) case of dp
		for(ll i = 1; i <= n; i++) dp[i] = F[i];
		
		// find the answer by either choosing or eliminating using dynamic programming
		dfs1(1, -1, adj);

		// root node will store the answer
		cout << dp[1] << "\n";
	}
}