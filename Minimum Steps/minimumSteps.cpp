/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/yogi-and-his-steps-65b27a4b/
	id: 160
	author: amir aghazadeh
*/


#include <iostream>
#include <algorithm>

using namespace std;

int LIS(int Arr[], int N)
{
    int lis[N];
    lis[0] = 1;
 
    for (int i = 1; i < N; i++)
	{
        lis[i] = 1;

        for (int j = 0; j < i; j++)
		{
			if (Arr[i] > Arr[j] && lis[i] < lis[j] + 1)
			{
                lis[i] = lis[j] + 1;
			}
		}
    }

    return *max_element(lis, lis + N);
}

int LDS(int Arr[], int N)
{
    int lds[N];
    int 
		i, 
		j, 
		max = 0;

    for (i = 0; i < N; i++)
	{
        lds[i] = 1;
	}

    for (i = 1; i < N; i++)
	{
        for (j = 0; j < i; j++)
		{
            if (Arr[i] < Arr[j] && lds[i] < lds[j] + 1)
			{
                lds[i] = lds[j] + 1;
			}
		}
	}

    for (i = 0; i < N; i++)
	{
        if (max < lds[i]) max = lds[i];
	}

    return max;
}

int main() {
	int N;
	cin >> N;

	int Arr[N];
	for(int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}

	int decreasingSteps = N - LDS(Arr, N);
	int increasingSteps = N - LIS(Arr, N);

	cout << min(decreasingSteps, increasingSteps) << endl;
}