/*Language: cpp
ID: 12c1cec6
QLink:www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/summing-the-weird-series-12c1cec6/
Author: @ellicoder */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000021
#define ROOT3 589781815
#define IOTA 484563811
 
ll modexp(ll x,ll n){
    if(n==0)return 1ll;
    if(n==1)return x%MOD;
    ll y=modexp(x,n/2);
    if(n%2==0)return (y*y)%MOD;
    else return (((y*y)%MOD)*x)%MOD;
}
 
ll add(ll x, ll p){
    x=(x%MOD+p%MOD)%MOD;
    x=(x+MOD)%MOD;
    return x;
}
 
ll sub(ll x, ll p){
    x=(x%MOD-p%MOD)%MOD;
    x=(x+MOD)%MOD;
    return x;
}
 
ll mul(ll x, ll p){
    x=((x%MOD)*(p%MOD))%MOD;
    return x;
}
 
ll divide(ll x, ll p){
    x=((x%MOD)*modexp(p%MOD,MOD-2))%MOD;
    return x;
}
 
ll helper(ll z, ll n){
    z%=MOD;
    ll x=sub(mul(n%MOD,z),1ll);
    x=mul(x,modexp(add(z,1ll),n));
    x=add(x,1ll);
    x=divide(x,mul(add(n%MOD,1ll),mul(z,z)));
    return x;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
    cin>>t;
    assert(1ll<=t&&t<=100000ll);
    while(t--)
    {
        ll n,k,ans,root3ik,one_plus_root3ik,one_minus_root3ik,a1,a2,pre,pre1,pre2;
        cin>>n>>k;
        assert(1ll<=n&&n<=1000000000000000000ll);
        assert(0ll<=k&&k<=1000000000000000000ll);
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        root3ik=mul(mul(ROOT3,IOTA),k%MOD);
        one_plus_root3ik=add(1ll,root3ik);
        one_minus_root3ik=sub(1ll,root3ik);
        pre=mul(root3ik,modexp(2ll,n-2));
 
        a1 = helper(divide(one_plus_root3ik,2ll),n);
        a2 = helper(divide(one_minus_root3ik,2ll),n);
 
        ans = mul(pre,sub(a1,a2));
 
        cout<<ans<<"\n";
    }
    
    return 0;
}