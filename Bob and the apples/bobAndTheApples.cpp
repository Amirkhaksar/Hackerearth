/**
 * @file bobAndTheApples.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-05-20
 * @id 168
 * @QLink https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/sengij-and-the-apples-c4b983b8/
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		int
			N,
			M;

		cin
			>> N
			>> M;

		int
			v[N],
			p[N];

		for(int j = 0; j < N; j++)
		{
			cin
				>> v[j]
				>> p[j];
		}

		vector<vector<vector<int>>> DP(N + 1, vector<vector<int>> (M + 1, vector<int> (2, 0)));

		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				DP[j][k][0] = DP[j - 1][k][0]; 
				DP[j][k][1] = DP[j - 1][k][1];

				if(k - p[j - 1] >= 0)
				{
						DP[j][k][1] = max(DP[j][k][1], max(v[j - 1] + DP[j - 1][k - p[j - 1]][1], v[j - 1] + DP[j - 1][k - (p[j - 1] / 2)][0]));
						DP[j][k][0] = max(v[j - 1] + DP[j - 1][k - p[j - 1]][0], DP[j - 1][k][0]);
				}
				else if(k - (p[j - 1] / 2) >= 0)
				{
					DP[j][k][1] = max(DP[j][k][1], v[j - 1] + DP[j - 1][k - (p[j - 1] / 2)][0]);
				}
			}
		}

		cout << DP[N][M][1] << endl;
	}
}