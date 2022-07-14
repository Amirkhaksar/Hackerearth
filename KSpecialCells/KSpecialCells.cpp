//Language: cpp
//ID: 294
//QLink: https://www.hackerearth.com/problem/algorithm/shinos-k-special-cells-c8538ebb/
//Author: hacker erth site Author ( Education for @mahdimma )

#include <iostream>


#define ll long long int
#define mod 1000000007

using namespace std;

const ll n = 1000001;
ll factorials[n];        
ll reverseFactorials[n];

ll power(ll number, ll power)
{ 
    ll base = 1;
    while (power != 1)
    {
        if (power % 2 == 0)
        {
            number = (number * number) % mod;
            power = power / 2;
        }
        else
        {
            base = (base * number) % mod;
            power--;
        }
    }
    return (base * number) % mod;
}

void storeFactorials()
{
    factorials[0] = factorials[1] = 1;
    reverseFactorials[0] = reverseFactorials[1] = 1;
    for (int i = 2; i < n; i++)
    {
        factorials[i] = (i * factorials[i - 1]) % mod;
        reverseFactorials[i] = (power(factorials[i], mod - 2)) % mod;
    }
}

ll nCr(ll n, ll r)
{
    ll nFact = factorials[n];
    ll nMinusR = reverseFactorials[n - r];
    ll rFact = reverseFactorials[r];
    return ((nFact * nMinusR) % mod * rFact) % mod;
}

int main()
{
    storeFactorials();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll totalStrength = 0;
        while (k--)
        {
            ll localStrength = 1;
            ll x, y, strength;
            cin >> x >> y >> strength;
            localStrength *= nCr(y + x - 2, x - 1);                            
            localStrength = (localStrength * nCr(n - x + m - y, n - x)) % mod; 
            localStrength = (localStrength * strength) % mod;                  
            totalStrength = (totalStrength + localStrength) % mod;             
        }
        cout << totalStrength << endl;
    }
    return 0;
}