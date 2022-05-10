//Language:c++
//ID:126
//Qlink:https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/one-sized-game/
//Author:@mahdimma

#include <iostream>

void quickSortIterative(int arr[], int indexs[], int l, int h);
int partition(int*, int*, int, int);
void subArr(int*, int, int, int);
int testIndex(int*, int*, int, int);
void game(int*, int*, int);

int main()
{
	int T = 0;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N = 0;
		std::cin >> N;
		int* arr = new int[N];
		int* indexs = new int[N];
		for (int i = 0; i < N; i++)
		{
			std::cin >> arr[i];
			indexs[i] = i;
		}
		quickSortIterative(arr, indexs, 0, N - 1);
		game(arr, indexs, N);
	}
}

void game(int* arr, int* indexs, int length)
{
	int i = 0;
	bool wonLadia = false;
	while (i < length)
	{
		if (i == length - 1)
		{
			wonLadia = true;
			break;
		}
		int decrease = 0;
		while (arr[i] - decrease >= 0)
		{
			decrease += indexs[i] + 1;
		}
		subArr(arr, i, length, decrease);
		i = testIndex(arr, indexs, i, length);
	}
	if (wonLadia)
	{
		std::cout << "Ladia" << std::endl;
		return;
	}
	else
	{
		std::cout << "Kushagra" << std::endl;
		return;
	}

}

int testIndex(int* arr, int* indexs, int start, int length)
{
	for (int i = start; i < length; i++)
	{
		if (arr[i] < 0)
		{
			int index = indexs[i];
			for (int j = i; j < length; j++)
			{
				if (indexs[j] > index)
				{
					indexs[j] -= 1;
				}
			}
		}
		else
		{
			return i;
		}
	}
}

void subArr(int* arr, int start, int length, int number)
{
	for (int i = start; i < length; i++)
	{
		arr[i] -= number;
	}
}

void quickSortIterative(int arr[], int indexs[], int l, int h)
{
	
	int *stack = new int[h - l + 1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0) {
		h = stack[top--];
		l = stack[top--];
		int p = partition(arr, indexs, l, h);
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

int partition(int* arr, int* indexs, int start, int end)
{
	int piv = arr[end];
	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (arr[j] <= piv)
		{
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			int indexTemp = indexs[j];
			indexs[j] = indexs[i];
			indexs[i] = indexTemp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	int indexTemp = indexs[i + 1];
	indexs[i + 1] = indexs[end];
	indexs[end] = indexTemp;
	return (i + 1);
}