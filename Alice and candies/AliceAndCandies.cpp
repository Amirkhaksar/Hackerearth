/*
#Language:C++
#ID:Alice and candies
#QLink:https://www.hackerearth.com/problem/algorithm/lola-and-candies-36b57b1b/
#All Accepet
#Author:Amirkhaksar
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

bool valid_pair(ll a , ll b)
{
	

	ll n2 = (a+b)/2;
	ll n1 = (a-b)/2;

	if(n1>=0 and n2>=0 and n2>=n1)return true;

	return false;
}

signed main()
{
    FIO;


	ll N,ans=0;
	cin>>N;


	for(ll i=1;i*i<=N;i++)
	{
		if(N%i==0)
		{
			ll a = i,b = N/i;

			if((a%2==0 and b%2==0) or (a%2 and b%2))
			{
				if(valid_pair(a,b))ans++;
				if(i*i!=N and valid_pair(b,a))ans++;
			}
		}
	}
	cout<<ans;
}