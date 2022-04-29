/*
#Language: cpp
#ID:thief-and-warehouses
#QLink:https://www.hackerearth.com/problem/algorithm/thief-and-warehouses-6ebf4e07/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define cases         \
    int testcases;    \
    cin >> testcases; \
    while (testcases--)
#define ENDL "\n"
#define ull unsigned long long int

int main()
{
    fast;
    cases
    {
        int n;
        cin >> n;
        ull a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ull ans = 0, maxi = 0, i = 0, tp = 0;
        stack<ull> st;

        while (i < n)
        {
            if (st.empty() || a[st.top()] <= a[i])
            {
                st.push(i);
                i++;
            }
            else
            {
                tp = st.top();
                st.pop();
                if (!st.empty())
                {
                    ans = a[tp] * (i - 1 - st.top());
                }
                else
                {
                    ans = a[tp] * i;
                }
            }
            maxi = max(maxi, ans);
        }

        while (!st.empty())
        {
            tp = st.top();
            st.pop();
            if (!st.empty())
            {
                ans = a[tp] * (i - 1 - st.top());
            }
            else
            {
                ans = a[tp] * i;
            }
            maxi = max(ans, maxi);
        }

        cout << maxi << ENDL;
    }
}