// In the name of Allah.
// We're nothing and you're everything.
// Ya Ali!
//Language:cpp
//ID:122
//Qlink:https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/snake-b0112afa/
//Author: hacker erth site test creater

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 14;
map<int, vector<pair<int, int> >> mp;
int ans[maxn];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        mp[x].push_back({y, i});
    }
    bool rev = false;
    int sz = 0;
    for(auto [x, vec] : mp){
        if(rev)
            sort(vec.begin(), vec.end(), greater<pair<int, int> >());
        else
            sort(vec.begin(), vec.end());
        for(auto [y, i] : vec)
            ans[i] = sz++;
        rev ^= 1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}