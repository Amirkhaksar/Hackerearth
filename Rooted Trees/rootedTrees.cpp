#include <bits/stdc++.h>

using namespace std;

/**
 * id: 211
 * author: amir aghazadeh (cssu-ama)
 * question link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/hemose-asking-bakry-about-trees-e9598556/
 * language: cpp
 */

typedef long long ll;

const int N = 1e5 + 14;
int n, y, q, st[N], en[N], a[N], ver[N];
vector<int> g[N];
set<int> ley;

void dfs(int v = 0, int p = -1) {
	static int time;
	if (p == -1)
		time = 0;
	ver[time] = v;
	st[v] = time++;
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
	en[v] = time;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q >> y;
		fill(g, g + n, vector<int>());
		fill(a, a + n, 0);
		for (int i = 0; i < n - 1; ++i) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		ley.clear();
		for (int i = 0; i < n; ++i)
			ley.insert(ley.begin(), i);
		dfs();
		while (q--) {
			int t, v;
			cin >> t >> v;
			--v;
			if (t == 0) {
				int x;
				cin >> x;
				auto it = ley.lower_bound(st[v]);
				while (it != ley.end() && *it < en[v]) {
					int u = ver[*it];
					a[u] += x;
					if (a[u] >= y)
						it = ley.erase(it);
					else
						++it;
				}
			}
			else
				cout << a[v] << '\n';
		}
	}
}