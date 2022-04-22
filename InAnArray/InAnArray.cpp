#include <iostream>
using namespace std;

#define ll long long

int main()
{

    int n, k, x, y;
    cin >> n >> k >> x >> y;
    ll a[1001] = {0};
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }

    ll ans = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }

        for (int j = i; j < 1001; j++)
        {
            if ((i + j) % k == x && (i * j) % k == y)
            {
                if (i == j)
                {
                    ans += (a[i] * (a[i] - 1)) / 2;
                }
                else
                {
                    ans += a[i] * a[j];
                }
            }
        }
    }
    cout << ans;

    return 0;
}