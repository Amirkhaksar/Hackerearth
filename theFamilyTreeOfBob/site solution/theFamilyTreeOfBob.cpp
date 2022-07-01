//Language: cpp
//ID: 232
//QLink: https://www.hackerearth.com/problem/algorithm/family-tree-of-aman-f2e011b3/
//Author: hacker erth site author

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> graph[500001];
int up[500001][2] = { 0 };

int main()
{
	int N, Q;
	cin >> N >> Q;
	int v, u;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	up[1][0] = -1;
	up[1][1] = 0;
	stack <int> stk;
	stk.push(1);
	int nowG;
	while (!stk.empty())
	{
		nowG = stk.top();
		stk.pop();
		for (int i = 0; i < graph[nowG].size(); i++)
		{
			if (up[graph[nowG][i]][0] == 0)
			{
				up[graph[nowG][i]][0] = nowG;
				up[graph[nowG][i]][1] = up[nowG][1] + 1;
				stk.push(graph[nowG][i]);
			}
		}
	}
	int k, ans;
	for (int i = 0; i < Q; i++)
	{
		cin >> v >> k;
		ans = v;
		if (k > up[ans][1])
		{
			cout << -1 << endl;
			continue;
		}
		if (k == up[ans][1])
		{
			cout << 1 << endl;
			continue;
		}
		for (int i = 0; i < k; i++)
		{
			ans = up[ans][0];
			if (ans == -1)
			{
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
