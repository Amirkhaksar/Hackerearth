/*
#Language:C++
#ID:Remove the element
#QLink:https://www.hackerearth.com/problem/algorithm/harry-and-horcrux-1-df65f8e9/
#All Accepet
#Author:Amirkhaksar
*/



#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define pb push_back
#define MAX 100005
const ll INF = 1e18;
const int mod = 1000000007;
ll arr[MAX], fact[MAX];
int main()
{
    ll t, n, m, i, j, k;
    fact[0] = 1;
    for (i = 1;i < MAX ;++i)
        fact[i] = (i * fact[i - 1]) % mod;
    cin >> t;
    while (t--)
    {
        cin>>n;
        for (i = 1;i <= n;++i)
            cin>>arr[i];
        sort(arr + 1, arr + n + 1, [](ll x, ll y)
            {
                return x > y;
            });
        ll ans = 0;
        for (i = 1;i <= n;++i)
            ans = (ans + fact[i] * arr[i]) % mod;
        cout<< ans;
    }
    return 0;
}