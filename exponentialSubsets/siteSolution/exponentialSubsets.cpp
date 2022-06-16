//Language: cpp
//ID: 198
//Qlink: https://www.hackerearth.com/problem/algorithm/exponential-subset-f78d066f/
//Author: hakerErth site Author solution

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector <int> vect;
		vector <int> sorted;
		int dp[10001] = { 0 };
		int temp;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			vect.push_back(temp);
			sorted.push_back(temp);
			dp[temp] += 1;
		}
		sort(sorted.begin(), sorted.end());
		int max = (sorted[N - 1] * N) + 1;
		for (int i = 1; i <= max; i++)
		{
			if (dp[i] == 0)
			{
				continue;
			}
			for (int j = max, z = max - i; j > i; j--, z--)
			{
				if (dp[j] == 0)
				{
					continue;
				}
				if (dp[j] == 1 && dp[z] > 0 && z < i)
				{
					continue;
				}
				dp[i + j] += dp[j];
			}
			int temp = dp[i];
			for (; temp > 1; temp--)
			{
				dp[temp * i] += 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			int temp = vect[i];
			int powed = temp * temp;
			bool flag = false;
			while (powed <= 10000)
			{
				if (dp[powed] > 0)
				{
					cout << "1 ";
					flag = true;
					break;
				}
				powed *= temp;
			}
			if (flag)
			{
				continue;
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}