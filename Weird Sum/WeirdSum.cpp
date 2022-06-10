#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf_neg -100000000000000ll
int n, m, k;
ll arr[10009];
ll dp[10009][1009];
int kk ;

ll solve(int idx, int k) {
	
	if(k == 0)
		return 0;
	
	if(idx == n)
		return inf_neg;
	
	if(dp[idx][k] != -1)
		return dp[idx][k];

	ll ans = solve(idx + 1, k);
	ans = max(ans, (arr[idx] * ((kk - k + 1) % m)) + solve(idx + 1, k - 1));

	return dp[idx][k] = ans;

} 

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin>>n>>k>>m;

	kk = k;

	for(int i = 0; i < n; i++)
		cin>>arr[i];

	// ll ans = solve(0, k);
	cout<<solve(0, k)<<endl;

	return 0;
}