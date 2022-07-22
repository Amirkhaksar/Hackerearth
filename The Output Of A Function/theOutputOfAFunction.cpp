/**
 * @file theOutputOfAFunction.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-07-22
 * @id 292
 * @questionLink https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/output-of-function-14aa5863/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll add(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

ll sub(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inverse(ll x)
{
    return binpow(x, mod - 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll p, q, r;
        cin >> p >> q >> r;
        ll n = sub(binpow(r, p * q), 1);
        ll temp = sub(binpow(r, p), 1);
        ll m = mul(binpow(r, p * q), temp);
        ll res = mul(n, inverse(m));
        cout << res << "\n";
    }
    return 0;
}