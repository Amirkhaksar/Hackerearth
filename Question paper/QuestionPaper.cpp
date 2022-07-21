/*
#Language:C++
#ID:Question paper
#QLink:https://www.hackerearth.com/problem/algorithm/entrance-examination-01e4a1b9/
#All Accepet
#Author:Amirkhaksar
*/

#include<bits/stdc++.h>
#define ll int
using namespace std;
bool visited[4000006];
queue<pair<ll, ll> > q;
void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, d, s, ans = 0;
        cin >> n >> a >> b;
        while (!q.empty())
            q.pop();
        s = n * b;
        d = n * a + s;
        q.push({ s,0 });
        memset(visited, 0, sizeof(visited));
        visited[s] = 1;
        while (!q.empty())
        {
            ll temp = q.front().first;
            ll lvl = q.front().second;
            q.pop();
            if (lvl >= n)
            {
                continue;
            }
            if (temp + a <= d)
            {
                if (!visited[temp + a])
                {
                    visited[temp + a] = 1;
                    q.push({ temp + a,1 + lvl });
                }
            }
            if (temp - b >= 0)
            {
                if (!visited[temp - b])
                {
                    visited[temp - b] = 1;
                    q.push({ temp - b,1 + lvl });
                }
            }
        }
        for (ll i = 0;i <= d;i++)
            ans += visited[i];
        cout << ans << "\n";
    }
}
int main()
{
    ll i, j, k;

    solve();

    return 0;
}