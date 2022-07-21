 /*
#Language:C++
#ID:A TV remote
#QLink:https://www.hackerearth.com/problem/algorithm/tv-and-remote-183262c5/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 14, mod = 1e9 + 7;
int n, fac[maxn], rfac[maxn];
int rev(int x){
    int ans = 1;
    for(int b = mod - 2; b; b >>= 1, x = (ll) x * x % mod)
        if(b & 1)
            ans = (ll) ans * x % mod;
    return ans;
}
int c(int n, int r){
    return (ll) fac[n] * rfac[r] % mod * rfac[n - r] % mod;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    fac[0] = rfac[0] = 1;
    for(int i = 1; i < maxn; i++){
        fac[i] = (ll) fac[i - 1] * i % mod;
        rfac[i] = rev(fac[i]);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i * 2 <= n; i++)
            ans = (ans + (ll) c(n, i) * c(n - i, i)) % mod;
        cout << ans << '\n';
    }
}