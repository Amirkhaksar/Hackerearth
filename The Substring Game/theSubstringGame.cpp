/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-substring-game-c14f8bd2/
	id: 153
	author: Amir Aghazadeh
*/


#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;cin>>s;

    ll n=(ll)s.size();

    ll pref[n+1]={0};

    ll val=n;

    for(ll i=1;i<=n;i+=1){

        pref[i]=val;

        pref[i]+=pref[i-1];

        val-=1;

    }

    ll q;cin>>q;

    while(q--){

        ll k;cin>>k;

        if(k<=n*(n+1)/2 && k>=1){

        auto i=lower_bound(pref,pref+n+1,k)-pref;

        k-=pref[i-1];

        string str=s.substr(i-1,k);

        cout<<str<<"\n";

        }

        else

        cout<<-1<<"\n";

    }

    return 0;

}