/*Language: cpp
ID: 99eacf3d
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/how-many-rbs-99eacf3d/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for le
using namespace __gnu_pbds;
using namespace std;

#define lln  long long 
#define fr(i,a,n) for(int i = a; i < n; i++)
#define pb push_back

lln gcd(lln a,lln b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    while(b){
        lln re = a % b;
        a = b;
        b = re;
    }
    return a;
}

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>	second;
 
vector<lln> pres(vector<lln> &v){
    int n = v.size();
    vector<lln> ans(n + 1, 0);
    fr(i, 1, n + 1) ans[i] = ans[i - 1] + v[i];
    return ans;
}
 
lln power(lln x, lln y, lln p)
{
    lln res = 1;     
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}

vector<int> primeFactors(int n){
    vector<int> ans;
    while (n % 2 == 0){
        ans.pb(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0){ 
            ans.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        ans.pb(n);
    return ans;
}
 
int main(){
    int t;
    cin >> t;
    lln mod = 1e9+7;
    while(t--){
        int n;
        cin >> n;
        vector<lln> dp(n + 1, 0);
        string s;
        cin >> s;
        if(s[0] == ')' || n % 2){cout << 0 << endl; continue;}
        s[0] = '(';
        dp[1]++;
        
        for(int i = 1; i < n; i++){
            vector<lln> ndp(n + 1, 0);
            for(int j = 0;j < n; j++){
                if(dp[j]){
                    if(s[i] == '(')	
                    ndp[j + 1] = (dp[j] + ndp[j + 1]) % mod;
                    else if(s[i] == ')'){
                            if(j > 0)ndp[j - 1] = (ndp[j - 1] + dp[j]) % mod;
                    }
                    else {
                    ndp[j + 1] = (dp[j] + ndp[j + 1]) % mod;	
                    if(j > 0)ndp[j - 1] = (ndp[j - 1] + dp[j]) % mod;
                    }
                }
            }
            dp=ndp;
        }
        cout << dp[0] << endl;
    }
}