//Language: cpp
//ID: 277
//QLink: https://www.hackerearth.com/problem/algorithm/archery-1/
//Author: @mahdimma

#include <iostream>
using namespace std;
typedef long long int ll;
ll num[49] = { 0 };

int GCD(ll A, ll B) {
	if (B == 0)
		return A;
	else
		return GCD(B, A % B);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		cin >> num[0] >> num[1];
		ll lcd = (num[0]/GCD(num[0],num[1])) * num[1];
		for (int i = 2; i < N; i++)
		{
			cin >> num[i];
			lcd = (num[i] / GCD(lcd, num[i])) * lcd;
		}
		cout << lcd << endl;
	}
}