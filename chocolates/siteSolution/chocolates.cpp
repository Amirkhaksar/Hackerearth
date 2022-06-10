//Language: cpp
//ID: 190
//Qlink: https://www.hackerearth.com/problem/algorithm/simon-amanda-and-the-last-chocolate-9db82979/
//Author: hakerErth site Author

#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1000;

bool dp[maxn][maxn];
int n, k, a[maxn];

string solve(){
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }
    for(int len = 1; len < n; len++){
        for(int i = 0; i + len < n; i++){
            int j = i + len;
            if(a[i] != a[j])
                continue;
            for(int l = 1; l <= k; l++){
                for(int p = 1; p <= k; p++){
                    if(i + l <= j - p){
                        dp[i][j] |= dp[i + l][j - p];
                    }
                }
            }
        }
    }
    return (dp[0][n - 1] ? "YES" : "NO");
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve();
    return 0;
}