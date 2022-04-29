#include <bits/stdc++.h>

using namespace std;

int KJump(int K, vector<int> A, int N)
{	
	vector<int> ans;

	for(auto a : A)
	{
		if(ans.empty() or (a - ans.back()) >= K)
		{
			ans.push_back(a);

		}
		else if(a > ans.back())
		{
			continue;
		}
		else
		{
			if(ans.size() == 1)
			{
				ans.back() = a;
				continue;
			}

			int idx = lower_bound(begin(ans), end(ans), a) - ans.begin();
			
			if(idx == 0 or (a - ans[idx - 1] >= K))
			{
				ans[idx] = a;
			}
		}
	}

	return ans.size();
}

int main() {
	int 
		K,
		N;
	
	cin 
		>> K 
		>> N;
	
	vector<int> A;

	for(int i = 0; i < N; i++)
	{
		int newElement;
		cin >> newElement;

		A.push_back(newElement);
	}

	cout << KJump(K, A, N);

	return 0;
}