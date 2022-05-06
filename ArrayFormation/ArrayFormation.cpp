/*Language: cpp
ID: 8e1319c9
QLink: www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int>st;
queue<int>q;

bool isPrime (int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      return false;
  return true;
}

void stackqueue (int arr[], int n)
{
  for (int i = 0; i < n; i++)
    {
      if (isPrime (arr[i]))
    	  q.push (arr[i]);
      else
    	  st.push (arr[i]);
    }

  while (!q.empty ())
    {
      cout << q.front () << " ";
      q.pop ();
    }
  cout << endl;
  while (!st.empty ())
    {
      cout << st.top () << " ";
      st.pop ();
    }
}

int main ()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
      cin >> arr[i];

  stackqueue (arr, n);

  return 0;
}
