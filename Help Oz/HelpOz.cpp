/*
#Language:C++
#ID:Help Oz
#QLink:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/a-simple-task/
#All Accepet
#Author:Amirkhaksar
*/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
#include<cassert>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define pb push_back
#define sz(x) int(x.size())
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
map<int,int> mapit;
set<int> st;
int arr[1000006];
vector<int> ans;
int main()
{
	int n,i,val,sqrtit,j,sz;
	si(n);
	assert(n>=2 && n<=100);
	rep(i,n)
	{
		si(arr[i]);
		assert(arr[i]>=2 && arr[i]<=1000000000);
	}
	sort(arr,arr+n);
	FOR(i,1,n)
	{
		val=arr[i]-arr[i-1];
		assert(val!=0);
		sqrtit=sqrt(val);
		FOR(j,1,sqrtit+1)
		{
			if(val%j==0)
			{
				mapit[j]++;
				mapit[val/j]++;
				st.insert(j);
				st.insert(val/j);
			}
		}
		if(sqrtit*sqrtit == val)
			mapit[sqrtit]--;
	}
	set<int>::iterator it;
	for(it=st.begin(); it!=st.end(); ++it)
	{
		val=*it;
		if(val==1)
			continue;
		if(mapit[val]==n-1)
			ans.pb(val);
	}
	sz=ans.size();
	rep(i,sz)
	{
		printf("%d",ans[i]);
		if(i!=sz-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}