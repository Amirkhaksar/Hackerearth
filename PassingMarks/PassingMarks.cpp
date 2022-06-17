/*
Language: C++
ID: passing-marks-efb0d732
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/passing-marks-efb0d732/
Author: AmirZoyber
*/

#include<bits/stdc++.h>


#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while(t--)
typedef long long int ll;

ll solve(){
    ll n;
    ll INF=1000000000000000ll;
    std::cin >> n;
    std::vector<ll>dp(n+5,0);
    std::vector<ll> marks(n), bound(n);
    std::vector<ll>temp(n);

    for (ll i = 0; i < n; i++) {
        std::cin >> marks[i] >> bound[i];
        dp[i + 1] = INF;temp[i] = i;}
    sort(temp.begin(), temp.end(), [&](const ll& i1, const ll& i2){
        return marks[i1] + bound[i1] < marks[i2] + bound[i2];
    });
    for (ll i = 0; i < n; i++) {
        int idx = temp[i];
        for (ll j = i; j >= 0; j--) {
            if (dp[j] <= marks[idx]) {dp[j + 1] = std::min(dp[j + 1], dp[j] + bound[idx]);}
            }
    }
    for (ll i = n; i >= 0; i--) {
        if (dp[i] < INF) {return i;}
    }
}

//main
int main() {
    std::FIO;
    test
    {std::cout<<solve()<<endl;}
	return 0;
}