//language: c++
//ID: 134
//Qlink:https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/score-game-fbf0cd0c/
//author: @mahdimma -- MohammadMahdi Abbasi

#include <iostream>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;

bool sortBySum(const pair<int, int>& a,
	const pair<int, int>& b)
{
	bool greaterVal = (2 * a.first) + a.second > (2 * b.first) + b.second;
	if (greaterVal)
	{
		return greaterVal;
	}
	else if ((2 * a.first) + a.second == (2 * b.first) + b.second)
	{
		return a.first > b.first;
	}
	else
	{
		return greaterVal;
	}
}

int main() {
	int t; cin >> t;
	for (int k = 0; k< t; k++)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> vect;
		unsigned int xi, yi;
		for (int i = 0; i < n; i++)
		{
			cin >> xi;
			vect.push_back(make_pair(xi, 0));
		}
		for (int i = 0; i < n; i++)
		{
			cin >> yi;
			vect[i].y = yi;
		}
		sort(vect.begin(), vect.end(), sortBySum);
		unsigned long long int sumAlice = 0;
		unsigned long long int sumBob = 0;
		for (int i = 0; i < n; i++)
		{
			sumAlice += vect[i].x;
		}
		for (int i = 0; i < n; i++)
		{
			xi = vect[i].x;
			yi = vect[i].y;
			sumBob += (xi + yi);
			sumAlice -= xi;
			if (sumBob > sumAlice)
			{
				cout << i + 1 << endl;
				break;

			}
		}
	}
}