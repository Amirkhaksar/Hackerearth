/*
@language: cpp
#ID:Minimize the value
#QLink:https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimize-the-magic-05a3986c/
#All Accepet
#Author:Amirkhaksar
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>val;
vector<int>v[100005];
bool vis[100005];
ll ans;
int n;
void bfs(int src)
{
    queue<pair<int, int> >q;
    int cnt = 1;bool f = 0;
    q.push({ src,cnt });
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (vis[node])continue;
        vis[node] = 1;
        if (node == 1)
        {
            if (v[node].size() < 2 && !f)q.push({ n + 1,level + 1 }), f = 1;
        }
        else
        {
            if (v[node].size() < 3 && !f)q.push({ n + 1,level + 1 }), f = 1;
        }
        ans += level * val[node];
        for (auto i : v[node])
        {
            q.push({ i,level + 1 });
        }
    }
}
int main()
{
    ll x;
    assert(cin >> n >> x);
    assert(n >= 1 && n <= 1e5);
    assert(x >= 1 && x <= 1e9);
    val.resize(n + 2);
    for (int i = 1;i <= n;i++)
        assert(cin >> val[i]), assert(val[i] >= 1 && val[i] <= 1e9);
    val[n + 1] = x;
    for (int i = 1;i <= n - 1;i++)
    {
        int x, y;
        assert(cin >> x >> y);
        assert(x >= 1 && x <= n);
        assert(y >= 1 && y <= n);
        assert(x != y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    for (int i = 1;i <= n;i++)assert(vis[i] == 1);
    cout << ans << "\n";
    return 0;
}
