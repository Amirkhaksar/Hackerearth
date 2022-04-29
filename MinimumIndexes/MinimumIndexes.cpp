/*
#Language:python
#ID:Minimum Indexes
#QLink:https://www.hackerearth.com/problem/algorithm/yassers-conditions-6cc26a09/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int num)
{

    int sum{};

    while (num > 0)
    {

        int a = num % 10;

        sum += a;

        num -= a;

        num /= 10;
    }

    return sum;
}

int main()
{

    int n, q;

    cin >> n >> q;

    int arr[n] = {};

    int sod[n] = {};

    for (int i{}; i < n; i++)
    {

        cin >> arr[i];

        sod[i] = sum_of_digits(arr[i]);
    }

    for (int i{}; i < q; i++)
    {

        int query;

        cin >> query;

        bool done{false};

        for (int j{query - 1}; j < n; j++)
        {

            if (sod[j] < sod[query - 1] && arr[j] > arr[query - 1])
            {

                done = true;

                cout << j + 1 << endl;

                break;
            }
        }

        if (done == false)

            cout << -1 << endl;
    }
}