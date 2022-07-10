//Language: cpp
//ID: 251
//QLink: https://www.hackerearth.com/problem/algorithm/monk-and-the-islands/
//Author: @mahdimma

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visit[10001];
int dist[10001] = { 0 };

int dfs(vector <int> graph[10001], int N)
{
	queue <int> qu;
	qu.push(1);
	visit[1] = true;
	int nowG;
	while (!qu.empty())
	{
		nowG = qu.front();
		qu.pop();
		for (int i = 0; i < graph[nowG].size(); i++)
		{
			if (visit[graph[nowG][i]] == false)
			{
				dist[graph[nowG][i]] = dist[nowG] + 1;
				visit[graph[nowG][i]] = true;
				qu.push(graph[nowG][i]);
			}
		}
	}
	return dist[N];
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector <int> graph[10001];
		int N, M, x, y;
		cin >> N >> M;
		if (N == 1)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cout << dfs(graph, N) << endl;
		for (int i = 0; i < 10001; i++)
		{
			graph[i].clear();
			visit[i] = false;
			dist[i] = 0;
		}
	}
}