/*Language: cpp
ID: 39399feb
QLink:www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/dexter-and-points-39399feb/
Author: @ellicoder */
#include <iostream> 
using namespace std;
#define MOD 1000000007
 
long long int func(long long int n){
    if (n == 0 || n == 1) return 0;
    else return n * ( n - 1 ) % MOD;
}

int main()
{
    int n, i;
    cin >> n;
    long long int a[n + 1];
    for(i= 0;i < n;i++)
        cin >> a[i];
    int count = 1;
    for(i = 0;i < n;i++)
        count = count * ((a[i] + 1) + func((a[i] + 1) / 2) + func((a[i] + 2) / 2)) % MOD;
    cout << count;
    return 0;
}
 