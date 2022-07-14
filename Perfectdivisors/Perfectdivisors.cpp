/*Language: cpp
ID: ac71a4ff
QLink:www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/perfect-divisors-ac71a4ff/
Author: @ellicoder */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
 
 
int mx=2e6+1;
vector<int> maxdiv(mx,-1);

ll powM(ll n, ll p) { return (!p ? 1 : (p & 1) ? (1ll * n * powM(n, p - 1)) % mod : powM((1ll * n * n) % mod, p / 2)); }
ll add(ll a, ll b) { return a + b - (a + b >= mod) * mod; }
ll sub(ll a, ll b) { return a - b + (a - b < 0) * mod; }
ll mul(ll a, ll b) { return (1ll * a * b) % mod; }
ll divM(ll a, ll b) { return (1ll * a * powM(b, mod - 2)) % mod; }
 
void f(){
	maxdiv[0]=0;
	maxdiv[1]=1;
	for(int i=2;i*i<mx;i++)	{
		if(maxdiv[i]==-1)		{
			maxdiv[i]=i;
			for(int j=i+i;j<mx;j+=i)
				maxdiv[j]=i;
		}
	}
	for(int i=2;i<mx;i++)
		if(maxdiv[i]==-1)	maxdiv[i]=i;
}
 
void solve(){
	ll n;
	cin>>n;
	vector<ll> ct(mx,0ll);
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		while(x>1)		{
			ct[ maxdiv[x] ]=add(ct[ maxdiv[x] ], y);
			x/=maxdiv[x];
		}
	}
	
	ll temp1,temp2,ans=1ll;
	for(int i=2;i<mx;i++){
		if(ct[i]==0)	continue;
		n=(ct[i]/2)+1;
		temp1= sub( powM((1ll*i*i)%mod,n),1);
		temp2=sub((1ll*i*i)%mod ,1);
		ans=mul( ans,divM(temp1,temp2) );
	}
	
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
 
	solve();
	return 0;
}