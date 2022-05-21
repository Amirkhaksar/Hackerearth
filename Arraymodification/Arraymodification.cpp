/*Language: cpp
ID: dc88ff8a
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/array-modification-2-dc88ff8a/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    long long int n; 
    cin >> n;
    long long int a[n], pref[n] ,suff[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i] = a[i];
        suff[i] = a[i];
    }
    for(int i = 1; i < n; i++)
        pref[i] += (pref[i - 1]) / 2;
    cout << endl;

    for(int i = n - 1; i > 0; i--)
        suff[i - 1] += (suff[i]) / 2;
    cout << endl;

    long long int ans = LONG_LONG_MIN;
    for(int i = 0; i < n; i++)
        ans = max(ans, pref[i] + suff[i] - a[i]);
    cout << ans << endl;

    return 0;
}