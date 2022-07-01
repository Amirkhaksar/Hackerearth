// Language: cpp
// ID: 177
// QLink: https://www.hackerearth.com/problem/algorithm/shift-and-replace-d96fc236/
// Author: hacker erth author's solution
// There was ambiguity between the question and the solution

#include <iostream>
#include <vector>
#include <queue>

#define ll long long int
#define MAX 1000000000000000000
using namespace std;
ll t[100000 + 5];
ll a[100000 + 5];
ll seg[5 * 100005];
priority_queue <pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
int n;

void build(int l, int r, int index)
{
    if (l == r)
    {
        seg[index] = t[l];
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);

    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

ll query(int l, int r, int ql, int qr, int index)
{
    if (r < ql || qr < l)
    {
        return MAX;
    }

    if (ql <= l && r <= qr)
    {
        return seg[index];
    }

    int mid = (l + r) / 2;

    return min(query(l, mid, ql, qr, 2 * index + 1), query(mid + 1, r, ql, qr, 2 * index + 2));
}

void update(int l, int r, int in, int val, int index)
{
    if (r < in || in < l) return;

    if (l == r && l == in)
    {
        seg[index] += val;
        return;
    }

    int mid = (l + r) / 2;
    update(l, mid, in, val, 2 * index + 1);
    update(mid + 1, r, in, val, 2 * index + 2);

    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

ll solve(int index, ll val)
{
    if (a[index] <= n)
    {
        int in = index - a[index] + 1;

        if (in >= 1)
        {
            update(1, n, in, 1, 0);
        }
        else
        {
            in = a[index] - index;
            in = n - in + 1;
            update(1, n, in, 1, 0);
        }
    }

    a[index] = val;

    if (a[index] <= n)
    {
        int in = index - a[index] + 1;

        if (in >= 1)
        {
            update(1, n, in, -1, 0);
        }
        else
        {
            in = a[index] - index;
            in = n - in + 1;
            update(1, n, in, -1, 0);
        }
    }

    return query(1, n, 1, n, 0);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }



    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= n)
        {
            int index = i - a[i] + 1;

            if (index >= 1) t[index]++;
            else
            {
                index = a[i] - i;
                index = n - index + 1;
                t[index]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        t[i] = i - 1 + n - t[i];
    }

    build(1, n, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int index;
        ll val;
        cin >> index >> val;
        cout << solve(index, val) << endl;
    }
}