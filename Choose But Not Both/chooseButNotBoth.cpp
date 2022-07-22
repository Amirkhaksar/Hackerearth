/**
 * @file chooseButNotBoth.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-07-22
 * @id 245
 * @language cpp
 * @questionLink https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/choose-but-not-both-0478f107/
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5+100;

int f[N];
bool mark[N], mark2[N];
vector<int> r[N];

ii dfs(int v){
    mark[v] = true;
	ii ret = ii(1, 0);
	for(auto u : r[v]){
		if(!mark[u]){
			ii cur = dfs(u);
			ret.second += max(cur.first, cur.second);
			ret.first += cur.second;
		}
	}
	return ret;
}

int solve_linear(vector<ii> v){
	int ls[2] = {0, 0};
	for(auto i : v){
		ls[1] += i.second;
		ls[0] += max(i.first, i.second);
		swap(ls[0], ls[1]);
	}
	return max(ls[0], ls[1]);
}

int solve(vector<int> cyc){
    for(auto i : cyc)
		mark[i] = true;
	vector<ii> v;
	for(auto i : cyc)
		v.push_back(dfs(i));

	if(v.size() == 1)
		return v[0].second;

	if(v.size() == 2){
		int ret = v[0].first + v[1].second;
		ret = max(ret, v[0].second + v[1].first);
		ret = max(ret, v[0].second + v[1].second);
		return ret;
	}

	// 1 is chosen
	int ret = [&]{
		vector<ii> cur;
		for(int i=3 ; i<v.size() ; i++)
			cur.push_back(v[i]);
		return max(v[1].first, v[1].second) + v[0].second + v[2].second + solve_linear(cur);
	}();

	// 1 is not chosen
	ret = max(ret, [&]{
		vector<ii> cur;
		for(int i=2 ; i<v.size() ; i++)
			cur.push_back(v[i]);
		cur.push_back(v[0]);
		return v[1].second + solve_linear(cur);
	}());

	return ret;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin >> n;
	for(int i=0 ; i<n ; i++){
		cin >> f[i];f[i] --;
		r[ f[i] ].push_back(i);
	}

	int ans=0;

	for(int i=0 ; i<n ; i++){
		if(mark[i])
			continue;
		// finding cycle
		auto cyc = [&]{	
			vector<int> cyc;
			int it = i;
			while(!mark2[it]){
				mark2[it] = true;
				cyc.push_back(it);
				it = f[it];
			}
			reverse(cyc.begin(), cyc.end());
			while(cyc.back() != it)
				cyc.pop_back();
			return cyc;
		}();
		ans += solve(cyc);
	}

	cout << ans << "\n";
}
