//Language: cpp
//ID: 225
//QLink: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/approximate/tennis-tournament-75939265/editorial/
//Author: @mahdimma
//this is a NP - Hard problem and this just my try to solve that's and not a correct solution.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;
vector <int> gamer[100000];
vector <int> win;
vector <int> temp;

bool BFS(int src, int dest, int pred[])
{
	list<int> queue;

	for (int i = 0; i < 100000; i++) {
		pred[i] = -1;
	}

	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < gamer[u].size(); i++) {
			pred[gamer[u][i]] = u;
			queue.push_back(gamer[u][i]);

			if (gamer[u][i] == dest)
			{
				return true;
			}
		}
	}
	return false;
}


vector <int> path(int src, int dest)
{
	int* pred = new int[100000];
	vector<int> path;
	if (BFS(src, dest, pred) == false) {

		delete[] pred;
		return path;
	}

	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	delete[] pred;
	return path;
}

vector <int> bfsFind(int start)
{
	queue <int> q;
	q.push(start);
	while (!q.empty())
	{
		int g = q.front();
		q.pop();
		for (int i = 0; i < gamer[g].size(); i++)
		{
			if (gamer[g][i] == start)
			{
				return path(start, g);
			}
			q.push(gamer[g][i]);
		}
	}
	vector <int> temp;
	return temp;
}


int main()
{
	int N, M;
	cin >> N >> M;
	int one, two;
	for (int i = 0; i < M; i++)
	{
		cin >> one >> two;
		gamer[one].push_back(two);
	}

	for (int i = 1; i <= N; i++)
	{
		temp = bfsFind(i);
		if (temp.size() < win.size() || win.size() == 0)
		{
			win = temp;
		}
	}
	if ( win.size() == 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < win.size(); i++)
	{
		cout << win[i] << " ";
	}
}

