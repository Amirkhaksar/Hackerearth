/*Language: cpp
ID: 123d6381
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/analytically-stable-123d6381/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(0);
    long long int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long int n = s.size();
        long long int dp1[n][10],dp2[n][10];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                dp1[i][j] = 0;
                dp2[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) 
                for (int j = 0; j<10; j++)
                    dp1[i][j] = dp1[i][j]+dp1[i-1][j];
            dp1[i][s[i]-'0']++;
        }

        for(int i = n-1; i >= 0; i--) {
            if(i!=n-1) 
                for(int j = 0; j<10; j++)
                    dp2[i][j] = dp2[i][j]+dp2[i+1][j];
            dp2[i][s[i]-'0']++;
        }   

        long long int ans = 0;

        for(int i = 1; i < n - 1; i++) {
            if(s[i] == '9') continue;
            long long int c1 = dp1[i - 1][s[i] - '0'];
            long long int c2 = dp2[i + 1][s[i] - '0' + 1];
            if(c2 != 0)
                ans = (ans + (c1 * ((c2 * (c2 - 1) / 2) % mod)) % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}