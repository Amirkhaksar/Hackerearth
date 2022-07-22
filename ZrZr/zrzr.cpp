/**
 * @file zrzr.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-07-22
 * @id 286
 * @questionLink https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/zrzr/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

int tests;
long long n, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin >> tests;
    for (; tests; --tests)
    {
        cin >> n;
        ans = 0;
        while (n)
        {
            ans += n / 5;
            n /= 5;
        }
        cout << ans << endl;
    }

    return 0;
}