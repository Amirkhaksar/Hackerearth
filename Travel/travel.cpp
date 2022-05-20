/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/travel-2-faeafba1/
	id: 167
	author: amir aghazadeh
*/


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++)
	{
		int
			N,
			K;
 
		cin
			>> N
			>> K;
 
		vector<pair<int, int>> A;
		for(int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
 
			A.push_back({a, j});
		}
 
		sort(A.begin(), A.end());
 
		int feasibility[N - K];
		for(int j = 0; j < N - K; j++)
		{
			feasibility[j] = 0;
			for(int k = j; k < j + K; k++)
			{
				int distance = abs(A.at(k).second - A.at(k + 1).second);
				feasibility[j] += distance;	
			}
		}
 
		if(K == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << *max_element(feasibility, feasibility + N - K) << endl;	
		}
	}
}