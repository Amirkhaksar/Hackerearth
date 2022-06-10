/**
 * @file anInterestingGame.cpp
 * @author amir aghazadeh (cssu-ama)
 * @version 0.1
 * @date 2022-06-03
 * @lan cpp
 * @Qlink https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/interesting-game-hard-93f267d9/
 * @id 207
 */

#include <bits/stdc++.h>

using namespace std;

const unsigned int mod = 1000000007;

int main()
{
  int numberOfTestCases;
  cin >> numberOfTestCases;

  while(numberOfTestCases)
  {
    int quantityOfNumbers;
    cin >> quantityOfNumbers;

    set<long> numbers;

    for(int i = 0; i < quantityOfNumbers; i++)
    {
      int number;
      cin >> number;

      numbers.insert(number);
    }

    long size = numbers.size();
    int result = 1;

    for(int i = 0; i < size - 1 - ((size % 2 == 1) ? 1 : 0); i++)
    {
      result = (result * 2) % mod;
    }

    cout << result << endl;

	numberOfTestCases--;
  }

  return 0;
}