//Language: cpp
//ID: 272
//QLink:https://www.hackerearth.com/problem/algorithm/the-confused-monk/
//Author: @mahdimma


#include <iostream>
#include <math.h>

using namespace std;

typedef long long int ll;
const ll monki = 1e9 + 7;
ll A[51] = { 0 };

int GCD(ll A, ll B) {
	if (B == 0)
		return A;
	else
		return GCD(B, A % B);
}

int modEPower(ll a, ll n)
{
	ll result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result = (result * a) % monki;
		}
		a = (a * a) % monki;
		n = n / 2;
	}
	return result;
}

int main()
{
	ll f = 1, g = 0, N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		f = (f * A[i]) % monki;
	}
	g = GCD(A[0], A[1]);
	for (int i = 2; i < N; i++)
	{
		g = GCD(g, A[i]);
		if (g == 1)
		{
			break;
		}
	}
	cout << modEPower(f, g);
	return 0;
}