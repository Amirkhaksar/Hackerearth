/*Language: cpp
ID: fb914aed
QLink:www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/too-much-to-count-fb914aed/
Author: @ellicoder */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define m 1000000

vector<ll> prime;
bitset<m> isprime;
vector<ll> divi(m+1);

void seive(){
    isprime.set();
    isprime[0]=isprime[1]=false;
    for(ll i=2;i<=m;i++){
        if(isprime[i]) {
            prime.pb(i);
            for(ll j=i*i;j<=m;j+=i)
                isprime[j]=false;
        }
    }
}

void div_seive(){
    for(ll i=2;i<=m;i++)
        for(ll j=1;i*j<=m;j++)
            divi[i*j]++;
}

ll totient(ll n){
    ll res=n;
    for(ll i=0;prime[i]*prime[i]<=n;i++) {
        if(n%prime[i]==0){
            res-=(res/prime[i]);
            while(n%prime[i]==0)
                n/=prime[i];
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    seive();
    div_seive();
    ll t,n,a;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(n-divi[n]-totient(n))<<"\n";
    }
    return 0;
}