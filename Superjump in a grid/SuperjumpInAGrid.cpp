/*
#Language:C++
#ID:Superjump in a grid
#QLink:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/superjump-in-a-grid-773f1e31/
#All Accepet
#Author:Amirkhaksar
*/
#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int recentRow[n][m], recentCol[n][m];
    int dp[n][m];
    for (int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        int x = 0;
        for (int j = 0;j < m;j++)
        {
            a[i][j] = (s[x++] - '0');
            recentRow[i][j] = -1;
            recentCol[i][j] = -1;
            dp[i][j] = 0;
        }
    }



    for (int i = 1;i < n;i++)
    {
        for (int j = 1;j < m;j++)
        {
            recentRow[i][j] = ((a[i][j - 1] == 0) ? j - 1 : recentRow[i][j - 1]);
            recentCol[i][j] = ((a[i - 1][j] == 0) ? i - 1 : recentCol[i - 1][j]);
        }
    }

    for (int i = 0;i < m;i++)
    {
        if (a[0][i] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 0;i < n;i++)
    {
        if (a[i][0] == 0)
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }

    for (int i = 1;i < n;i++)
    {
        for (int j = 1;j < m;j++)
        {
            if (a[i][j] == 0) {
                if (recentRow[i][j] != -1)
                    dp[i][j] = (dp[i][j] % 1000000007 + dp[i][recentRow[i][j]] % 1000000007) % 1000000007;
                if (recentCol[i][j] != -1)
                    dp[i][j] = (dp[i][j] % 1000000007 + dp[recentCol[i][j]][j] % 1000000007) % 1000000007;
            }
        }
    }
    if (a[n - 1][m - 1] != 1 and a[0][0] != -1)
        cout << dp[n - 1][m - 1] << endl;
    else
        cout << 0 << endl;



}
