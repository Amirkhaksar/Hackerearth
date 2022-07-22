/**
 * @file bennyAndTheUniverse.cpp
 * @author amir aghazadeh (cssu-ama)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 * @id 269
 * @questionLink https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/benny-and-the-universe/
 * @language cpp
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, tests;
int d[N];
set<pair<int, int>> S;
set<pair<int, int>>::iterator it;
int dist[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> tests;

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d, d + n);

    for (int i = 0; i < d[0]; i++)
    {
        dist[i] = 2e9 + 1e6;
    }

    dist[0] = 0;

    for (int i = 0; i < d[0]; i++)
    {
        S.insert(make_pair(dist[i], i));
    }

    while (S.size())
    {
        it = S.begin();
        int v = (*it).second;
        S.erase(it);
        if (dist[v] > 1e9 + 1e8)
            continue;

        for (int i = 0; i < n; i++)
        {
            int new_val = dist[v] + d[i];
            int rem = new_val % d[0];

            if (dist[rem] > new_val)
            {
                S.erase(make_pair(dist[rem], rem));
                dist[rem] = new_val;
                S.insert(make_pair(dist[rem], rem));
            }
        }
    }

    for (; tests; --tests)
    {
        int val;
        cin >> val;
        long long R = val % d[0];
        if (dist[R] <= val)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}