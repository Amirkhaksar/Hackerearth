//Language: cpp
//ID: 258
//QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/great-graphs-afc1a343/
//Author: @mahdimma
//site compiler not work correctly

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

bool visitedg[100001];
vector <int> graph[100001];

int dfsFunc(int start)
{
	int len = 1;
	stack <int> q;
	q.push(start);
	visitedg[start] = true;
	int ver;
	while (!q.empty())
	{
		ver = q.top();
		q.pop();
		for (int j = 0; j < graph[ver].size(); j++)
		{
			if (visitedg[graph[ver][j]] == false )
			{
				visitedg[graph[ver][j]] = true;
				q.push(graph[ver][j]);
				len++;
			}
		}
	}
	return len;
}

int main()
{
	int N, M, F;
	cin >> N >> M >> F;
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int maxn = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visitedg[i] == false)
		{
			int len = dfsFunc(i);
			if (maxn < len)
			{
				maxn = len;
			}
		}
	}
	int ans = maxn / F;
	cout << ans;
}