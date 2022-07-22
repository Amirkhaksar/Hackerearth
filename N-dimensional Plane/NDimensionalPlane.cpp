/**
 * @file NDimensionalPlane.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-07-22
 * @id 299
 * @questionLink https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/counting-in-n-dimensional-b13b1ee2/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define fastIO cout << fixed << setprecision(4), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
const int N = 2e5 + 9, MOD = 1e9 + 7, OO = 1e9;
const ll INF = 1e15;

int fact[N];

int mul(int x, int y)
{
    return (1ll * x * y) % MOD;
}

int fastpow(int x, int pow)
{
    int ret = 1;
    while (pow)
    {
        if (pow & 1)
            ret = mul(ret, x);
        pow /= 2;
        x = mul(x, x);
    }
    return ret;
}

int modInv(int x)
{
    return fastpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, modInv(y));
}

int ncr(int n, int r)
{
    if (r > n)
        return 0;
    return divide(fact[n], mul(fact[r], fact[n - r]));
}

void preprocess()
{
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);
}

void runtestcase()
{
    int n, total = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        vec[i] = abs(vec[i]);
        total += vec[i];
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans = mul(ans, ncr(total, vec[i]));
        total -= vec[i];
    }
    cout << ans << '\n';
}

int main()
{
    fastIO;
#ifdef LOCAL
    freopen("file.in", "r", stdin);
#endif
    preprocess();
    int t = 1;
    cin >> t;
    while (t--)
        runtestcase();
}