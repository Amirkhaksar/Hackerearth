/*Language: cpp
ID: 1-0315faf6
QLink:www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/help-1-0315faf6/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio (false);

  cin.tie (NULL);
  long long int n, x, y;
  cin >> n;

  vector<pair <long long, long long >> d (n + 1);
  d[0] = make_pair (0, 0);

  for (int i = 1; i <= n; i++){
      cin >> x >> y;
      d[i] = make_pair (x, y);
    }

  sort (d.begin (), d.end ());
  long long int D, F;
  cin >> D >> F;

  int ans = 0, c = D;
  bool flag = true;

  priority_queue<long long>q;

  for (int i = n; i >= 0; i--) {
      F -= (c - d[i].first);
      if (F >= 0){
	  q.push (d[i].second);
	  c = d[i].first;
    	}
      else {
	  while (F < 0 && !q.empty ()) {
	      F += q.top ();
	      q.pop ();
	      ans++;
	    }

	  if (F < 0) {
	      flag = false;
	      break;
	    }
	  q.push (d[i].second);
	  c = d[i].first;

    	}
    }
  if (flag)
      cout << ans;
  else
    cout << -1;
}
