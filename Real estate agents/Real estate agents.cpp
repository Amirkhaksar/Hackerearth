/*
language = c++

id = Real estate agents

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/real-estate-1-059f5228/

author: amir hejazi

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int maxm = 1e5 + 20;

int l[maxm] , r[maxm] , c[maxm] , has[maxn] , n;

ll dp[maxn] , pd[maxn] , sum[maxn][maxn];

vector<int> all;

ll eval(int x , int y)
{
	return pd[x] + sum[all[x] + 1][all[y] - 1];
}

int get(int x , int y) // x > y she
{
	int l = max(x , y) , r = all.size();
	if(eval(x , l) > eval(y , l))
		return l;

	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if(eval(x , m) > eval(y , m))
			r = m;
		else
			l = m;
	}

	return r;
}

int prv[maxn] , nxt[maxn] , a[maxn] , id , where[maxn];
vector<int> pos[maxn];

void add(int val , int p)
{
	int k = nxt[p];
	where[val] = id;
	a[id] = val;
	prv[k] = id;
	nxt[p] = id;

	nxt[id] = k;
	prv[id] = p;
	id++;
}

void rm(int val)
{
	int p = where[val];
	prv[nxt[p]] = prv[p];
	nxt[prv[p]] = nxt[p];
	where[val] = 1e9;
}

void build()
{
	memset(where , 63 , sizeof where);
	memset(a , 63 , sizeof a);

	nxt[0] = 1;
	prv[1] = 0;
	prv[0] = 1e9;
	nxt[1] = 1e9;
	id = 2;
}

void handle(int p)
{
	int x = a[p] , y = a[nxt[p]];
	if(x > maxn || y > maxn)
		return;

	int k = get(x , y);
	pos[k].pb(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i] >> c[i];
		has[l[i]]++ , has[r[i] + 1]--;

		sum[l[i]][r[i]] += c[i];
	}

	for(int i = 1; i <= n; i++)
		has[i] += has[i - 1];

	for(int i = 1; i <= n; i++)
		if(has[i])
			all.pb(i);

	if((int)all.size() < k)
		return cout << -1 << endl , 0;

	for(int l = n; l >= 1; l--)
		for(int r = l + 1; r <= n; r++)
			sum[l][r] += sum[l][r - 1] + sum[l + 1][r] - sum[l + 1][r - 1];

	all.pb(n + 1);
	memset(dp , -63 , sizeof dp);

	for(int i = 0; i < (int)all.size(); i++)
		dp[i] = sum[1][all[i] - 1];

	for(int j = 2; j <= k + 1; j++)
	{
		memcpy(pd , dp , sizeof dp);
		memset(dp , -63 , sizeof dp);

		for(int i = 0; i < maxn; i++)
			pos[i].clear();
		build();

		for(int i = 0; i < (int)all.size(); i++)
		{
			for(auto x : pos[i])
				if(where[x] < maxn)
				{
					int p = prv[where[x]];
					while(a[p] < maxn && a[nxt[p]] < maxn && eval(a[p] , i) > eval(a[nxt[p]] , i))
						rm(a[nxt[p]]);
					handle(p);
				}

			if(prv[1])
				dp[i] = eval(a[prv[1]] , i);

			add(i , prv[1]);
			handle(prv[where[i]]);
		}
	}

	cout << sum[1][n] - dp[(int)all.size() - 1] << endl;
}

