/*Language: cpp
ID: 6064aa64
QLink:www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "", t = "";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s += char(x + '0');
    }

    t = s;
    sort(t.begin(), t.end());
    queue<string> q;
    q.push(s);
    map<string, int> visit;
    visit[s] = 1;

    while(!q.empty()) {
        string temp = q.front();
        q.pop();
        if(temp == t)
            break;
        for(int i = 2;i <= temp.size(); i++){
            string z = temp;
            reverse(z.begin(), z.begin() + i);
            if(visit[z] == 0){
                visit[z] = visit[temp] + 1;
                q.push(z);
            }
        }
    }
    cout << visit[t] - 1;

    return 0;
}