/*Language: cpp
ID: 123
QLink:www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-dragon-type-123/
Author: @ellicoder */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
 
const int sz = 1e5+5;
int A[sz];
int fastExpo(int a, int n, int mod) {
  int result = 1;
  while (n > 0) {
    if (n & 1)
      result = (result * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return result;
}
 
int modInverse(int n, int mod) { return fastExpo(n, mod - 2, mod); }
const int facsz = 2;
int Fact[facsz];
int inFact[facsz];
void factorial() {
  Fact[0] = inFact[0] = 1;
  for (int i = 1; i < facsz; i++) {
    Fact[i] = (Fact[i - 1] * i) % MOD;
    inFact[i] = modInverse(Fact[i], MOD);
  }
}
 
int __nCr(int n, int r, int mod) {
  if (r > n || r < 0)
    return 0;
  return Fact[n] * inFact[n - r] % mod * inFact[r] % mod;
}
void solve() {
  int n, p;
  cin >> n >> p;
 
  for(int i = 0; i < n ; i++){
    int x;
    cin >> x;
    x %= p;
    A[x]++;
  }
  int ans = A[0];
  for(int i  = 1 ; i < sz ; i++){
    if(A[i] == 0)continue;
    int x = modInverse(i, p);
    if(i == x)continue;
    int f = A[x];
    ans += max(f, A[i]);
    A[i] = A[x] = 0;
  }
  cout << ans <<endl;
 
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();

    return 0;
}