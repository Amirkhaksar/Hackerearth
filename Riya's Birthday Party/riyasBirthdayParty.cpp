/**
 * @file riyasBirthdayParty.cpp
 * @author amir aghazadeh (cssu-ama)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 * @id 275
 * @questionLink https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/riyas-birthday-party-1/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define mod 1000000007

#define endl "\n"

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;

    cin >> t;

    while (t--)

    {

        ll n;

        cin >> n;

        ll ans = (1 + (((2 * n + 1) % mod) * ((n - 1) % mod)) % mod) % mod;

        cout << ans << endl;
    }
}