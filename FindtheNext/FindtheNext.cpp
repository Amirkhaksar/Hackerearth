/*Language: cpp
ID: 6f89250c
QLink:www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/yet-to-keep-6f89250c/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  int n, q;
  cin >> n >> q;
  int long long arr[n + 1];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  map < long long, long long > mp;
  sort (arr, arr + n);
  for (int i = 0; i < n;) {
      int j = i;
      for (; j < n - 1; j++)
    	if (arr[j] < arr[j + 1] - 1)
	      break;
        for (int k = i; k <= j; k++)
	        mp[arr[k]] = arr[j];
            i = j + 1;
    }
  while (q--) {
    long long x;
    cin >> x;
    if (mp[x] == 0) {
	if (mp[x + 1] == 0)
	   cout << x + 1 << "\n";
	else
	   cout << mp[x + 1] + 1 << "\n";
	    }
    else
    	cout << mp[x] + 1 << "\n";
    }
  return 0;
}
