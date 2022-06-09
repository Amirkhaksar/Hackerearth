//Language: cpp
//ID: 206
//Qlink: https://www.hackerearth.com/problem/algorithm/path-maximum-bb1a923a/
//Author: @mahdimma

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;


void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}


bool BFS(vector<int> adj[], int src, int dest, int v,
	int pred[], int dist[])
{
	list<int> queue;

	bool* visited = new bool[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = 2147483647;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
				{
					delete[] visited;
					return true;
				}
			}
		}
	}
	delete[] visited;
	return false;
}


vector<int> getShortestDistance(vector<int> adj[], int s,
	int dest, int v)
{
	int* pred = new int[v];
	int* dist = new int[v];
	vector<int> path;
	if (BFS(adj, s, dest, v, pred, dist) == false) {
		cout << "Given source and destination"
			<< " are not connected";
		delete[] pred;
		delete[] dist;
		return path;
	}

	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	delete[] pred;
	delete[] dist;
	return path;
}

int main()
{
	int N, Q;
	cin >> N >> Q;
	int v = N + 1;

	vector<int>* adj = new vector<int>[v];
	vector<int> val(N + 1);
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> temp1;
		val[i] = temp1;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> temp1 >> temp2;
		add_edge(adj, temp1, temp2);
	}
	int source = 0, dest = 0;
	vector<int> path;
	for (int i = 0; i < Q; i++)
	{
		cin >> source >> dest;
		if (source == dest)
		{
			cout << val[source] << endl;
			continue;
		}
		path = getShortestDistance(adj, source, dest, v);
		int max = 0;
		for (int i = 0; i < path.size(); i++)
		{
			max = val[path[i]] < max ? max : val[path[i]];
		}
		cout << max << endl;
	}
	return 0;
}
