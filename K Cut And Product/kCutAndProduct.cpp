/**
 * @file kCutAndProduct.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-05-31
 * @id 185
 * @lan cpp
 * @Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/k-cut-and-product-e5998b3f/
 * 
 */


#include<bits/stdc++.h>

using namespace std;

const long long mod = 720720;

int main()
{
	int totalNumberOfElements;
	cin >> totalNumberOfElements;

	int elements[totalNumberOfElements + 1];
	for(int i = 1; i < totalNumberOfElements + 1; i++)
	{
		cin >> elements[i];
    elements[i] = elements[i] % mod;
	}

	int cutsQuantity;
	cin >> cutsQuantity;

  long long dp[cutsQuantity + 1][totalNumberOfElements + 1][totalNumberOfElements + 1][2];

	for(int i = 1; i < totalNumberOfElements + 1; i++)
  {
    for(int j = i; j < totalNumberOfElements + 1; j++)
    {
      if(i == j)
      {
        dp[0][i][j][0] = elements[i];
        dp[0][i][j][1] = 1;
      }
      else
      {
        dp[0][i][j][0] = (dp[0][i][j - 1][0] * elements[j]) % mod;
        dp[0][i][j][1] = 1;
      }
    }
  }

  for(int i = 1; i < cutsQuantity + 1; i++)
  {
    for(int j = 1; j < totalNumberOfElements + 1; j++)
    {
      for(int k = j + 1; k < totalNumberOfElements + 1; k++)
      {
        long long temp = 0;
        for(int l = j; l < k - i + 1; l++)
        {
          temp = (temp + ((dp[0][j][l][0] * dp[i - 1][l + 1][k][1]) + (dp[0][j][l][1] * dp[i - 1][l + 1][k][0]))) % mod;
          dp[i][j][k][1] = (dp[i][j][k][1] + (dp[0][j][l][1] * dp[i - 1][l + 1][k][1])) % mod;
        }
        dp[i][j][k][0] = temp;
      }
    }
  }

  cout << dp[cutsQuantity][1][totalNumberOfElements][0] << endl;
}
