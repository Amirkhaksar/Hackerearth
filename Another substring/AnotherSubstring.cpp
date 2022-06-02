/*
#Language:C++
#ID:AnotherSubstring
#QLink:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/another-substring-problem-900ce141/
#All Accepet
#Author:Amirkhaksar
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> CurCount;
vector<int> Reqd;

set<int> s;

int n,k;

void pre()
{
	a.clear();
	s.clear();
	CurCount.clear();
	a.resize(n+1);
	CurCount.resize(k+1,0);
	Reqd.resize(k+1,1);
}

void solve()
{
	cin>>n>>k;
	assert(n <= 100000);
	assert(k <= 10000);
	pre();
	for(int i=0;i<n;i++) cin>>a[i];
	int ans = 999999999; 
	int cnt = 0;
	int tmp = 999999999;
	int x=0,y=n-1;
	for(int begin=0, end=0; end < n ; end++)
	{
		if(Reqd[a[end]] == 0) continue;
		CurCount[a[end]]++;
		if(CurCount[a[end]] <= Reqd[a[end]])
			cnt++;
		if(cnt == k)
		{
			while(Reqd[a[begin]] == 0 ||
				  CurCount[a[begin]] > Reqd[a[begin]])
			{
				if(CurCount[a[begin]] > Reqd[a[begin]])
					CurCount[a[begin]]--;
				begin++;
			}
			
			tmp = end - begin + 1;
			
			if(tmp <= ans)
			{
				
				ans = tmp;
			}
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	assert(t <= 10);
	while(t--) solve();
}