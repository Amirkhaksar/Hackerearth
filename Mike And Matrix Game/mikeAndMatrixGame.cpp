/**
 * @file mikeAndMatrixGame.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-07-22
 * @id 298
 * @questionLink https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/approximate/matrix-game-9febd80a/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int arr[MAXN][MAXN];
double fact[MAXN];
int n, k;

double get(int num)
{
    return exp(fact[num] + fact[k] + fact[n - k] - (fact[n] + fact[k - 1] + fact[num - (k - 1)]));
}

int main()
{
    int i, j, x;
    double P, p, ans;
    for (i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] + log(i);
    scanf("%d %d %d", &n, &k, &x);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[j][i]);

    ans = 0;
    for (i = 0; i < n; i++)
    {
        sort(arr[i], arr[i] + n);
        P = 1;
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] + x < arr[i][n - 1] || j < k - 1)
                continue;
            p = get(j);
            ans += p * (arr[i][j] + x);
            P -= p;
        }
        ans += P * (arr[i][n - 1]);
    }
    printf("%.7lf\n", ans);
    return 0;
}