//language: c++
//ID: 221
//Qlink:https://www.hackerearth.com/problem/algorithm/areas-0475fb6e/
//author: @mahdimma -- MohammadMahdi Abbasi

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

short** arr;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		arr = new short* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new short[M];
		}
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '#')
				{
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = 1;
				}
			}
		}
		vector <int> vect;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 1)
				{
					arr[i][j] = 0;
					int sum = 1;
					// i , j
					stack<pair<int, int>> stk;
					pair<int, int> pai;
					stk.push(make_pair(i, j));
					while (!stk.empty())
					{
						pai = stk.top();
						int z = pai.first, s = pai.second;
						stk.pop();
						if (z != 0 && arr[z - 1][s] == 1)
						{
							arr[z - 1][s] = 0;
							sum++;
							stk.push(make_pair(z - 1, s));
						}
						if (z != N - 1 && arr[z + 1][s] == 1)
						{
							arr[z + 1][s] = 0;
							sum++;
							stk.push(make_pair(z + 1, s));
						}
						if (s != 0 && arr[z][s - 1] == 1)
						{
							arr[z][s - 1] = 0;
							sum++;
							stk.push(make_pair(z, s - 1));
						}
						if (s != M - 1 && arr[z][s + 1] == 1)
						{
							arr[z][s + 1] = 0;
							sum++;
							stk.push(make_pair(z, s + 1));
						}

					}
					vect.push_back(sum);

				}
			}
		}
		cout << vect.size() << endl;
		for (int i = 0; i < vect.size(); i++)
		{
			cout << vect[i] << (i == vect.size() - 1 ? "" : " ");
		}
		cout << endl;
	}
}