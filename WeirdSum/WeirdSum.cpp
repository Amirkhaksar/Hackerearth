/*Language: cpp
ID: 1d2a0a2e
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/weird-sum-1d2a0a2e/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fo(i, b, n) for (int i = b; i < n; ++i)

const long long int oo = 1e18;
long long int n, k, m, a[10002], dp[1002][10002];

void solution () {
  cin >> n >> k >> m;
  fo (i, 1, n + 1) cin >> a[i];
  fo (i, 0, k + 1) fo (j, 0, n + 1) dp[i][j] = -oo;
  fo (i, 0, n + 1) dp[0][i] = 0;
  fo (i, 1, k + 1)  {
    fo (j, 1, n + 1) dp[i][j] = dp[i - 1][j - 1] + a[j] * (i % m);
    fo (j, 1, n + 1) dp[i][j] = max (dp[i][j], dp[i][j - 1]);
  }
  cout << dp[k][n];
}

int main () {
    solution ();
    return 0;
}
