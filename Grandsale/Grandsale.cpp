/*Language: cpp
ID: 14b23729
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hi-1-14b23729/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define loop(i,a,b) for(int i=(a);i<=b;i++)
 
ll n, m, t, k ;
ll dp[100001]; 
 
void cal(){
    loop(i, 0, 100001)
        dp[i] = 0;
 
    loop(i,1,n){
        ll a, b, c, d ;
        cin >> a >> b >> c >> d;
        a = a * 60 + b;
        c = c * 60 + d + 5;
        dp[a]++;
        dp[c]--;
    }
    ll ans = 0;
    loop(i, 1, 100000){
        dp[i] = dp[i] + dp[i - 1];
        ans = max(dp[i], ans);
    }
    cout << ans ;
}
 
int main(){
    cin >> n;
    cal();
 
    return 0;
}