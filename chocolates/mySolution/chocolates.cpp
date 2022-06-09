//Language: cpp
//ID: 190
//Qlink: https://www.hackerearth.com/problem/algorithm/simon-amanda-and-the-last-chocolate-9db82979/
//Author: @mahdimma

#include <iostream>
using namespace std;
int ini[1001];

int main()
{
	int N, k;
	cin >> N >> k;
	int iPrev = 1;
	int jPrev = N - 2;
	for (int i = 0; i < N; i++)
	{
		cin >> ini[i];
	}
	if (ini[0] != ini[N-1])
	{
		cout << "NO";
		return 0;
	}
	for (int i = iPrev; i < iPrev + k; i++)
	{
		for (int j = jPrev; j > jPrev - k; j--)
		{
			if (ini[i] == ini[j])
			{
				iPrev = i + 1;
				jPrev = j - 1;
				if (i == j)
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
