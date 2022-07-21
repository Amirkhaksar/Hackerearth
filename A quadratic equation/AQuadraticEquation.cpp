/*
#Language:C++
#ID:A quadratic equation
#QLink:https://www.hackerearth.com/problem/algorithm/quadratic-equation-4-22fecbd9/
#All Accepet
#Author:Amirkhaksar
*/


#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

#define endl "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

ll get(ll n)
{
    // B^2 - X^2 = C
    // B and X must have same parity

    ll ans = 0;
    for (ll X = 1;X * X <= n;X++)
    {
        ll B = n / X;

        if (X % 2) {
            // B and X should be odd
            ans += (B + 1) / 2 - (X - 1) / 2;
        }
        else {
            // B and X both should be even
            ans += (B / 2) - (X - 2) / 2;
        }
    }

    return ans;
}

signed main()
{
    FIO;

    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;

        cout << get(r) - get(l - 1) << endl;
    }

}