//Language: cpp
//ID: 235
//QLink: https://www.hackerearth.com/problem/algorithm/one-and-only-flow-740e0808/
//Author: @mahdimma
// i can't find any graph with N != 2 and M != 2 which have "Maxflow = 1" for all of that's vertexs

#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int N, M, u, v, g[3] = {0};
	bool yes = false;
	int i = 0;
	while (t--)
	{
		i = 0;
		cin >> N >> M;
		if (N == 2 && M == 2)
		{
			cin >> u >> v;
			g[u] = v;
			cin >> u >> v;
			g[u] = v;
			if (g[1] == 2 && g[2] == 1)
			{
				yes = true;
			}
			g[1] = 0;
			g[2] = 0;
			i = 2;
		}
		char ch[100];
		for (; i < M; i++)
		{
			cin >> u >> v;
		}
		if (yes)
		{
			cout << "Yes" << endl;
			yes = false;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}