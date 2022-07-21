/*
#Language:C++
#ID:Mike and GCD Issues
#QLink:https://www.hackerearth.com/problem/algorithm/mike-and-gcd-issues/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;
int divisor[nax];
vector<int> divisors[nax];
vector<int> where[nax];
bool range(int a, int b, int c) { return a <= b && b <= c; }
int main() {
	for(int i = 2; i * i < nax; ++i)
		if(!divisor[i])
			for(int j = i * i; j < nax; j += i)
				divisor[j] = i;
	for(int i = 1; i < nax; ++i) if(!divisor[i]) divisor[i] = i;
	
	int n;
	scanf("%d", &n);
	assert(range(1, n, 200 * 1000));
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		assert(range(1, x, 200 * 1000));
		while(x > 1) {
			int div = divisor[x];
			divisors[i].push_back(div);
			where[div].push_back(i);
			while(x % div == 0) x /= div;
		}
	}
	for(int i = 1; i <= n; ++i) {
		int best = -1;
		auto consider = [&](int j) {
			if(best == -1 || make_pair(abs(j - i), j)
						< make_pair(abs(best - i), i))
				best = j;
		};
		for(int prime : divisors[i]) {
			const vector<int> & vec = where[prime];
			int j = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
			if(j != 0) consider(vec[j-1]);
			if(j != (int) vec.size() - 1) consider(vec[j+1]);
		}
		printf("%d ", best);
	}
	puts("");
	assert(scanf("%d", &n) == EOF);
}