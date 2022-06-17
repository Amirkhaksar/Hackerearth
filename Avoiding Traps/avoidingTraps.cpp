/**
 * @file avoidingTraps.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-06-04
 * @id 174
 * lan cpp
 * Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/avoid-traps-0b92455e/
 */

#include <bits/stdc++.h>

using namespace std;

bool vis [100000 + 1];
int pri [100000 + 1];
int dp [1000000 + 1];
int siz = 0;
int N = 100000 + 1;
int t , n , r1 , r2;
string s;

void sieve()
{
  for(long long i = 2; i * i < N; i++)
  {
    if(!vis[i])
    {

      for(long long j = i * i; j < N; j += i)
      {
        vis[j] = true;
      }
    }
  }

  for(int i = 2; i < N; i++)
  {
    pri[i] = pri[i - 1] + !vis[i];
  }
}

int rec(int index)
{
  if(index == n) return 0;
  
  if(dp[index] != -1) return dp[index];
  
  int mini1 = 1e9;
  
  if(index + 1 <= n && s[index + 1] != '*') mini1 = min(mini1 , 1 + rec(index + 1));

  if(index + 2 <= n && s[index + 2] != '*') mini1 = min(mini1 , 1 + rec(index + 2));

  if(pri[index] * r2 >= index * r1 && (index + pri[index] <= n) && ( s[index + pri[index]] != '*') )
  
  mini1 = min(mini1, 1 + rec(index + pri[index]));

  return dp[index] = mini1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  sieve();
  
  cin >> t;

  while(t--)
  {
    memset(dp , -1, sizeof dp);

    cin >> r1 >> r2 >> n;
    cin >> s;

    s = "0" + s;

    if(s[n] == '*' || s[1] == '*')
    {
      cout << "No way!\n";

      continue;
    }
    
    int ans = rec(1);

    if(ans == 1e9) cout << "No way!\n";
    else cout << ans << "\n";
  }

  return 0;
}