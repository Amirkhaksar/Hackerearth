"""
#Language:C++
#ID:A good subset
#QLink:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/good-subset-88fda603/
#All Accepet
#Author:Amirkhaksar
"""


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e3 + 14;
int n, k;
int a[N];
bitset<N> dp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			dp.reset();
			dp[0] = true;
			for (int j = 0; j < n; ++j)
				if (i != j)
					dp |= dp << a[j];
			bool nec = false;
			for (int j = max(0, k - a[i]); j < k; ++j)
				nec |= dp[j];
			ans += !nec;
		}
		cout << ans << '\n';
	}
}