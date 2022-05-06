#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int T;
	cin >> T;

	int counter = 0;
	
	for(int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		vector<pair<int , int>> vector;
		for(int j = 0; j < N; j++)
		{
			int 
				S,
				E;
				
			cin
				>> S
				>> E;
				
			vector.push_back({E, 1});	
			vector.push_back({S, -1});
		}
		
		sort(vector.begin(), vector.end());
		
		int
			answer = 0,
			sum = 0;
			
		for(int j = 0; j < vector.size(); j++)
		{
			sum += vector[j].second;
			answer = max(answer, sum);
		}
		
		cout << answer << endl;
	}	
}