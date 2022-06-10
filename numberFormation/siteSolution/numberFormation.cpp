//Language: cpp
//ID: 186
//Qlink: https://www.hackerearth.com/problem/algorithm/number-formation-1cae96c5/
//Author: hakerErth site Author

#include<bits/stdc++.h>
#define LL long long int
#define M 720720
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
LL dp[100001][31];
int a[100001];
int main()
    {
        ios_base::sync_with_stdio(0);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int k;
        cin >> k;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            int st = 1;
            if(a[i] == 0){
                st = 2;
                dp[i][1] = dp[i - 1][1];
            }
            for(int j = st; j <= k; j++){
                dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] %= M;
            }
        }
        if(k == 1){
            cout << n;
        }
        else{
            cout << dp[n][k];
        }
    }

