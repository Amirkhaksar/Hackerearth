//Language: cpp
//ID: 248
//QLink: https://www.hackerearth.com/problem/algorithm/zero-path-a7d370fd/ 
//Author: @mahdimma

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int val[100001] = { 0 };
int re[100001] = { 0 };

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		int x, y;
		for (int i = 0; i < N - 1; i++)
		{
			cin >> x >> y;
			re[x]++;
			re[y]++;
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> val[i];
		}
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (val[i] != 0 && re[i] > 1)
			{
				sum++;
			}
		}
		cout << sum << endl;
		for (int i = 1; i <= N; i++)
		{
			val[i] = re[i] = 0;

		}
	}
}