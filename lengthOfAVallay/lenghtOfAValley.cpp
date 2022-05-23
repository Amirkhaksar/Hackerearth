//Language: cpp
//ID: 170
//QLink: https://www.hackerearth.com/problem/algorithm/hill-150045b2/
//Author: @mahdimma (MohammadMahdi Abbasi)

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int T, N, A;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> vect;
		for (int i = 0; i < N; i++)
		{
			cin >> A;
			vect.push_back(A);
		}
		int forward = 0;
		int back = 0;
		for (int i = 0, z; i < N;)
		{
			z = i;
			forward = 0;
			if (z != N - 1 && vect[z] == vect[z + 1])
			{
				cout << back + 1 << ' ';
				back = 0;
				i++;
				continue;
			}
			while (z != N - 1 && vect[z] < vect[z + 1])
			{
				forward++, z++;
			}
			if (forward == 0)
			{
				cout << back + 1 << ' ';
				back++;
				i++;
				continue;
			}
			for (; forward >= 0; i++, forward--)
			{
				if (back != 0)
				{
					cout << back + forward + 1 << ' ';
					back = 0;
					continue;
				}
				cout << forward + 1 << ' ';
			}
			if (vect[i] == vect[i - 1])
			{
				back = 0;
			}
			else
			{
				back = 1;
			}
		}
		cout << endl;
	}
}