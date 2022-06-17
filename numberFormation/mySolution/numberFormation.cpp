//Language: cpp
//ID: 186
//Qlink: https://www.hackerearth.com/problem/algorithm/number-formation-1cae96c5/
//Author: @mahdimma

#include <iostream>
#include <vector>
using namespace std;
int dp[100001][31];
int main()
{
	int N, K, inTemp;
	cin >> N;
	vector <int> vectZero;
	for (int i = 0; i < N; i++)
	{
		cin >> inTemp;
		if (inTemp == 0)
		{
			vectZero.push_back(N - i);
		}
	}
	cin >> K;
	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 1; j <= K; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= 720720;
		}
	}
	int zSize = vectZero.size();
	int tempZero;
	int out = dp[N][K];
	for (int i = 0; i < zSize; i++)
	{
		tempZero = vectZero[i];
		if (tempZero < K)
		{
			break;
		}
		out -= dp[tempZero - 1][K - 1];
	}
	while (out < 0)
	{
		out += 720720;
	}
	if (K == 1)
	{
		cout << N;
	}
	else
	{
		cout << out;
	}
}