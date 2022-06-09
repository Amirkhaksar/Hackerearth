//Language: cpp
//ID: 198
//Qlink: https://www.hackerearth.com/problem/algorithm/exponential-subset-f78d066f/
//Author: @mahdimma
//that's my solution before seeing site Author solution, and not work correctly

#include<iostream>
#include <vector>

using namespace std;

typedef long long int ll;
const int mxn = 1e4 + 2;
int main() {
    ll t; 
    cin >> t; 
    while (t--)
    {
      ll n; cin >> n;
      vector<ll>a(n);
      for (auto& it : a) cin >> it;
      vector<bool>dp(mxn,false);
      dp[0] = true;
      for (int i = 0; i < n; i++) {
          for (int j = mxn - 1; j >= 0; j--) {
              //if a number exist which can sum with a[i] and creat j, dp[j] = true
              if (j - a[i] >= 0 && dp[j - a[i]]) {
                  dp[j] = true;
              }
          }
      }
      vector<ll>ans(n,0);
      for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
              ans[i] = 1;
          }
          else {
              ll x = a[i] * a[i];
              while (x < mxn) {
                  if (dp[x]) {
                      ans[i] = 1;
                  }
                  x *= 2;
              }
          }
      }
      for (auto it : ans) {
          cout << it << " ";
      }
      cout << endl;
    }
    return 0;
}