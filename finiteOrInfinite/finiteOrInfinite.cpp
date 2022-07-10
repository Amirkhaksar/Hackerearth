//Language: cpp
//ID: 288
//QLink: https://www.hackerearth.com/problem/algorithm/is-it-finite-36fe70d5/
//Author: @mahdimma
// with help from Editorial
//The question was ambiguous and I realized that only examples
//containing L equal to one can be finite because only the coefficients are removed and the rest of the numbers remain.
// m * L for some other L like 2, 3, 4... and can't include all of natural number.
// like Sieve of Eratosthenes just remove some number

#include <iostream>
using namespace std;

int GCD(int A, int B)
{
	if (B == 0)
	{
		return A;
	}
	else
	{
		return GCD(B, A % B);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		bool finite = false;
		int l = 0, g = 0;
		cin >> g;
		for (int i = 1; i < N; i++)
		{
			cin >> l;
			g = GCD(g, l);
		}
		if (g == 1)
		{
			cout << "FINITE" << endl;
		}
		else
		{
			cout << "INFINITE" << endl;
		}
	}
}