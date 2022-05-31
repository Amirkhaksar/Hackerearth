/**
 * @file subsequences.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-05-31
 * @lan cpp
 * @id 176
 * @Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/subsequence-again-19245c50/
 * 
 */

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define sky LONG_LONG_MAX
#define ajen LONG_LONG_MIN
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<ll>ans;
  queue<ll>q;

  q.push(1);
  q.push(3);
  q.push(5);
  q.push(7);
  q.push(9);
  
  while(q.size() < 1e5)
  {
    ll x = q.front();
    q.pop();
    ans.push_back(x);

    q.push(x*10);
    q.push(x*10+1);
    q.push(x*10+2);
    q.push(x*10+3);
    q.push(x*10+4);
    q.push(x*10+5);
    q.push(x*10+6);
    q.push(x*10+7);
    q.push(x*10+8);
    q.push(x*10+9);
  }

  while(!q.empty())
  {

    ll x = q.front();
    ans.push_back(x);
    q.pop();
  }

  ll n; 
  cin >> n;

  while(n--)
  {
    ll k;
    cin >> k;

    cout << 1 << " " << ans[k - 1] << endl;
  }

  return 0;
}