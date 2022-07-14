//Language: cpp
//ID: 247
//QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/
//Author: @mahdimma

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int N, M, I, J;
	cin >> N >> M >> I >> J;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << max(abs(i - I), abs(j - J)) << (j == M - 1? "": " ");
		}
		cout << (i == N - 1 ? "" : "\n");
	}
}