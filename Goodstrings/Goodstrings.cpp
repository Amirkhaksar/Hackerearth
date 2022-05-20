/*Language: cpp
ID: cf18dfcb
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/good-strings-2-cf18dfcb/
Author: @ellicoder */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    long long int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0;i < n;i++){
        cin >> s;
        int flag0 = 0, flag1 = 0;
        for(int i = 0; i < s.length();i++){
            if(s[i] == '0')
                flag0 = 1;
            else
                flag1 = 1;
        }
        if(flag0 && flag1)
            cnt2++;
        else if(flag0)
            cnt0++;
        else
            cnt1++;
    }
    long long int res = cnt1 * cnt2 + cnt0 * cnt2 + (cnt2 * (cnt2 - 1)) / 2 +(cnt0 * (cnt0 - 1)) / 2 + (cnt1 * (cnt1 - 1)) / 2;
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}