"""
#Language:C++
#ID:Special graphs
#QLink:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/special-graph-2-3b2bf33c/
#All Accepet
#Author:Amirkhaksar
"""
#include<iostream>
#define ll long long int
using namespace std;
int prime[1000009];

void sieve(int n)
{
    bool pr[n+1];
    for(int i = 1 ; i <= n ; i++)
        pr[i] = true;

    pr[1] = false;

    for(int i = 2 ; i <= sqrt(n) ; i++)
    {
        if(pr[i])
        {
            for(int j = i*i ; j <= n ; j += i)
            {
                pr[j] = false;
            }
        }
    }

    for(int i = 2 ; i <= n ; i++)
    {
        if(pr[i] == true)
        {
            prime[i]++;
        }
    }

    for(int i = 2 ; i <= n ; i++)
    {
        prime[i] += prime[i-1];
    }
}

int main(){
    sieve(1000000);

    int q;
    cin>>q;

    while(q--)
    {
        int n;
        cin>>n;

        cout<<prime[n]<<endl;
    }
}