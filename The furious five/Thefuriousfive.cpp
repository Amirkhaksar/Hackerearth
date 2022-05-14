/*
#Language:C++
#ID:The furious five
#QLink:https://www.hackerearth.com/problem/algorithm/the-furious-five-69521576/
#All Accepet
#Author:Amirkhaksar
*/



#include<iostream>
using namespace std;

#define INF INT_MAX
#define pb push_back
#define mod (int)(1e9 + 7)
#define ll long long int

inline ll helper(ll n)
{
    ll ans = 0, calc;
    ans += n;
    calc = 5;
    while (n / calc != 0)
    {
        ans += (n / calc);
        calc *= 5;
    }
    return ans;
}
int main()
{
    int t, i;
    ll calc, s = 0, n, cnt, low, high, mid, c1, c2;
    cin >> t;
    assert(t >= 1 && t <= 100000);
    while (t--)
    {
        cin >> n;
        assert(n >= 1 && n <= 1000000000);
        low = 0;
        high = mod;
        while (low <= high)
        {
            mid = (low + high) / 2;
            c1 = helper(mid);
            c2 = helper(mid + 1);
            if (c1 < n && c2 >= n)
            {
                cout << 5 * (mid + 1) ;
                break;
            }
            else if (n > c1)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}