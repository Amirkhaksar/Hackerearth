//language: c++
//ID: 145
//Qlink:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bags-of-coins-7b1d612c/
//author: @mahdimma -- MohammadMahdi Abbasi


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	int N;
	cin >> N;
	if (N == 1)
	{
		cout << "YES";
		return 0;
	}
	vector<int> vect;
	int number[100001];
	for (int i = 0; i < 100001; i++)
	{
		number[i] = 0;
	}
	int input = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (number[input] == 0)
		{
			number[input] = 1;
			vect.push_back(input);
			continue;
		}
		number[input]++;
	}
	if (vect.size() == 1)
	{
		cout << "YES";
		return 0;
	}
	sort(vect.begin(), vect.end());
	unsigned long long int sumLeft = 0;
	unsigned long long int sumRight = 0;
	for (int i = 0, j = vect.size() - 1; i <= j;)
	{
		if (sumLeft == sumRight && j == i)
		{
			cout << "YES";
			return 0;
		}
		else if (sumLeft < sumRight)
		{
			sumLeft += vect[i] * number[vect[i]];
			i++;
		}
		else
		{
			sumRight += vect[j] * (number[vect[j]]);
			j--;
		}
	}
	cout << "NO";
	return 0;
}
