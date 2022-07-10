//Language: cpp
//ID: 264
//QLink: https://www.hackerearth.com/problem/algorithm/till-the-end-of-the-time-d73ba7d1/
//Author: @mahdimma
//The solution is correct, but the question has two ambiguities.
//One: The meaning of proximity is not clear and only {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}  is intended.
//Two: If all 1's cannot be converted into 2's, -1 should be printed.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e3 + 1;
int arr[maxn][maxn] = { 0 };
bool visit[maxn][maxn];
queue <pair<pair<int, int>, int>> qu;

int main()
{
	int N, M, k;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				qu.push({ { i,j }, 0 });
				visit[i][j] = true;
			}
		}
	}
	int t = 0, x, y;
	pair <pair<int, int>, int> p;
	while (!qu.empty())
	{
		p = qu.front();
		qu.pop();
		x = p.first.first;
		y = p.first.second;
		t = max(p.second, t);
		if (x - 1 >= 0 && visit[x - 1][y] == false && arr[x - 1][y] == 1)
		{
			arr[x - 1][y] = 2;
			qu.push({ {x - 1,y},(p.second + 1) });
			visit[x - 1][y] = true;
		}
		if (x + 1 < N && visit[x + 1][y] == false && arr[x + 1][y] == 1)
		{
			arr[x + 1][y] = 2;
			qu.push({ {x + 1,y},(p.second + 1) });
			visit[x + 1][y] = true;
		}
		if (y - 1 >= 0 && visit[x][y - 1] == false && arr[x][y - 1] == 1)
		{
			arr[x][y - 1] = 2;
			qu.push({ {x ,y - 1},(p.second + 1) });
			visit[x][y - 1] = true;
		}
		if (y + 1 < M && visit[x][y + 1] == false && arr[x][y + 1] == 1)
		{
			arr[x][y + 1] = 2;
			qu.push({ {x,y + 1},(p.second + 1) });
			visit[x][y + 1] = true;
		}
	}
	for (int i = 0; i < N && t != -1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				t = -1;
				break;
			}
		}
	}
	cout << t;
	return 0;
}