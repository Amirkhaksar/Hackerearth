/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/rooms-1/
	author: Amir Aghazadeh
	id: 138
*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define pob pop_back

#define pf push_front

#define pof pop_front

#define mp make_pair

#define all(a) a.begin(),a.end()

#define bitcnt(x) __builtin_popcountll(x)

#define MOD 1000000007

#define total 5000005

#define M 1000000000001

#define NIL 0

#define MAXN 100001

#define EPS 1e-5

#define INF (1<<28)

typedef unsigned long long int uint64;

typedef long long int int64;

int a[100005];

vector<pair<int,int> >v;

priority_queue<int,vector<int>,greater<int> >p;

int main()

{

ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int i,j,t,n,s,d;

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(i=0;i<n;i++)

        scanf("%d",&a[i]);

        for(i=0;i<n;i++){

            scanf("%d",&d);

            v.pb(mp(a[i],a[i]+d));

        }

        sort(all(v));

        int cnt=1;

        p.push(v[0].second);

        for(i=1;i<v.size();i++){

            d=v[i].first;

            j=p.top();

            if(d>=j){

                p.pop();

                p.push(v[i].second);

            }

            else{

                cnt++;

                p.push(v[i].second);

            }

        }

        printf("%d\n",cnt);

        v.clear();

        p=priority_queue<int,vector<int>,greater<int> >();

    }

    return 0;

}