"""
#Language:C++
#ID:Arrays and sums
#QLink:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/array-and-sums-6e5e7323/
#All Accepet
#Author:Amirkhaksar
"""

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 14;
const int mod = 1e9 + 7;
int n, a[maxn];
int dp[maxn], tmp[maxn];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill(dp, dp + maxn, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            for(int j = maxn - 1; j >= a[i]; j--){
                dp[j] += dp[ j - a[i] ];
                if(dp[j] >= mod)  dp[j] -= mod;
            }
        memcpy(tmp, dp, sizeof dp);
        for(int i = 0; i < n; i++){
            memcpy(dp, tmp, sizeof dp);
            for(int x = a[i]; x < maxn; x++){
                dp[x] += mod - dp[ x - a[i] ];
                if(dp[x] >= mod)  dp[x] -= mod;
            }
            cout << (!a[i] || dp[a[i]]) << ' ';
        }
        cout << '\n';
    }
}