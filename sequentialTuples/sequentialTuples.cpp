//Language: cpp
//ID: 163
//QLink: https://www.hackerearth.com/problem/algorithm/sequential-tuples-ea494c73/
//Author: @mahdimma (MohammadMahdi Abbasi)

#include <iostream>

int main()
{
	int arr[5];
	arr[1] = 1;
	arr[2] = 4;
	arr[3] = 10;
	arr[4] = 18;
	int N;
	std::cin >> N;
	while (N--)
	{
		int T;
		std::cin >> T;
		std::cout << ((T <= 4) ? arr[T] : arr[4] + (9 * (T - 4))) << std::endl;
	}
}