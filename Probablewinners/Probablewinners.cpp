/*Language: cpp
ID: 96715358
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/probable-winners-96715358/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using VI=vector<int>;
 
int main(){
	int testcase;
	for (cin >> testcase; testcase > 0; testcase--){
		int n;
		cin >> n;
		n += 2;
		vector<VI> a(n, VI(n));
		FOR(i, 1, n - 1) FOR(j, 1, n - 1) cin >> a[i][j];
		vector<VI> f(n, VI(n));
		for (int s = n - 1; s >= 0 ; s--) FOR(t, s + 1, n)
			if (s + 1 == t)
				f[s][t] = 1;
			else{
				FOR(m, s + 1, t) if ((a[s][m] || a[t][m]) && f[s][m] && f[m][t]){
					f[s][t] = 1;
					break;
				}
			}
		int ret = 0;
		FOR(i, 1, n - 1) if (f[0][i] && f[i][n - 1]) ++ret;
		printf("%d\n", ret);
	}
	return 0;
}