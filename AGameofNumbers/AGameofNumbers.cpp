/*Language: cpp
ID: 5d3a8cb3
QLink: www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
Author: @ellicoder */
#include <iostream>
using namespace std;

int main ()
{
  int n;
  cin >> n;
  int arr[n] = { };

  for (int i = 0; i < n; i++)
      cin >> arr[i];

  int greater_index[n] = { };

  bool done = false;
  int smaller[n] = { };

  for (int i = 0; i < n; i++)
    {
      done = false;
      for (int j = i; j < n; j++)
	    {
    	  if (arr[j] > arr[i])
            {
                greater_index[i] = j;
                done = true;
                break;
            }
	    }
      if (done == false)
    	greater_index[i] = -1;
    }

  for (int i = 0; i < n; i++)
    {
      done = false;
      for (int j = i; j < n; j++)
    	{
        if (arr[j] < arr[i])
            {
                smaller[i] = arr[j];
                done = true;
                break;
            }
	    }
    if (done == false)
    	smaller[i] = -1;
    }

  for (int i = 0; i < n; i++)
    {
      if (greater_index[i] == -1)
	    cout << -1 << ' ';
      else
	    cout << smaller[greater_index[i]] << ' ';
    }
}
