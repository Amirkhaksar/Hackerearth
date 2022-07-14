/*Language: cpp
ID: 270
QLink:www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/just-shortest-distance-problem/
Author: @ellicoder */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <set>
#include <iomanip>
#include <numeric>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define int long long
#define pb push_back
#define vi vector <int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
 
int distence[10001];
vi adj[10001];
 
void update(int node) {
	for(auto child : adj[node]) {
		if(distence[child] > distence[node] + 1) {
			distence[child] = distence[node] + 1;
			update(child);
		}
	}
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    rep(i, 0, 1001)
    	distence[i] = INT_MAX;
	distence[0] = 0;
    int n, m;
    cin >> n >> m;
    while(m--) {
    	int type;
    	cin >> type;
    	if(type == 1) {
    		int x;
    		cin >> x;
    		x--;
    		distence[x] >= INT_MAX ? cout << "-1" : cout << distence[x];
    		cout << "\n";
    	}
    	else {
    		int a, b;
    		cin >> a >> b;
    		a--, b--;
    		adj[a].pb(b);
    		if(distence[b] > distence[a] + 1) {
    			distence[b] = distence[a] + 1;
    			update(b);
    		}
    	}
    }
    return 0;
}