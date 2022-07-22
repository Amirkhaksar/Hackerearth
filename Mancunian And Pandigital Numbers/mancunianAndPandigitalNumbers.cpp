/**
 * @file mancunianAndPandigitalNumbers.cpp
 * @author amir aghazadeh (cssu-ama)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 * @id 278
 * @questionLink https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/mancunian-and-pandigital-numbers-1/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
int arr[MAXN];
int suff[MAXN];

bool valid(int n)
{
    int i, l;
    string s;
    while (n)
    {
        s += (n % 10 + '0');
        n /= 10;
    }
    sort(s.begin(), s.end());
    l = s.size();
    for (i = 0; i < l; i++)
        if (s[i] != '0' + i + 1)
            return false;
    return true;
}

void init()
{
    int i;
    for (i = 1; i < MAXN; i++)
    {
        arr[i] = valid(i);
        suff[i] = suff[i - 1] + arr[i];
    }
}

int main()
{
    int i, j, t, a, b;
    init();
    scanf("%d", &t);
    assert(t <= 100000);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        assert(1 <= a && a <= 1000000 && 1 <= b && b <= 1000000);
        printf("%d\n", suff[b] - suff[a - 1]);
    }
    return 0;
}