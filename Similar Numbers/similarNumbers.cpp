/**
 * @file similarNumbers.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-05-31
 * @id 188
 * @lan cpp
 * @Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/numbers-2-a9a00311/
 * 
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int
  MAX_N = 1e4 + 14,
  MAX_K = 114,
  MOD = 1e9 + 7;

int dp[MAX_N][MAX_K];

int main() 
{
	int
		telephoneNumberLength,
		K;

	cin
		>> telephoneNumberLength
		>> K;
	
	string phoneNumber;
	cin >> phoneNumber;

	dp[0][0] = 1;

  for (int i = 0; i < telephoneNumberLength; i++)
  {
    for (int j = 0; j <= K; j++)
    {
      dp[i + 1][j] = dp[i][j];
      if(j)
      {
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] * ll(1 + (phoneNumber[i] != '0' && phoneNumber[i] != '9'))) % MOD;
      }
    }
  }

  cout << accumulate(dp[telephoneNumberLength] + 1, dp[telephoneNumberLength] + K + 1, 0ll) % MOD << '\n';
}