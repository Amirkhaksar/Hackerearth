//Language: cpp
//ID: 238
//QLink: https://www.hackerearth.com/problem/algorithm/kavirioo-back-up-754d2621/
//Author: @mahdimma

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100001;
int degree[maxn] = { 0 };
int upDegree = 2;
vector <int> out;

int main()
{
	int N;
	cin >> N;
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
		if (degree[v] > upDegree)
		{
			upDegree = degree[v];
		}
		if (degree[u] > upDegree)
		{
			upDegree = degree[u];
		}
	}
	if (N == 2)
	{
		cout << 2 << endl << "1 2";
		return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == upDegree)
		{
			out.push_back(i);
		}
	}
	int len = out.size();
	cout << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << out[i] << ((i == len) ? "" : " ");
	}
	return 0;
}
