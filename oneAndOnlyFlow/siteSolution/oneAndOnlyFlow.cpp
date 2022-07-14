//Language: cpp
//ID: 235
//QLink: https://www.hackerearth.com/problem/algorithm/one-and-only-flow-740e0808/
//Author: hacker erth author solution

#include  <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n, m, tot[maxn];
bool vis[maxn], onstk[maxn], ans;
vector<int> g[maxn];

void dfs(int u) {
	vis[u] = onstk[u] = 1;
	for(int v : g[u]) {
		if(vis[v]) {
			if(!onstk[v]) {
				ans = 0;
			} else {
				tot[v]--;
				tot[u]++;
			}
		} else {
			dfs(v);
			tot[u] += tot[v];
		}
	}
	if(u != 1 and tot[u] != 1) {
		ans = 0;
	}
	onstk[u] = 0;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if(u != v) {
				g[u].emplace_back(v);
			}
		}
		fill(vis, vis + n + 1, 0);
		fill(tot, tot + n + 1, 0);
		ans = 1;
		dfs(1);
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += vis[i];
		if(cnt != n) {
			ans = 0;
		}
		if(ans) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}