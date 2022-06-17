/*Language: cpp
ID: 08331a99
QLink:www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/making-friends-08331a99/
Author: @ellicoder */
#include <iostream>
using namespace std;

int main() {
    int i, n, m, num;
    cin >> num;

    for(i = 0; i < num; i++){
      cin >> n >> m;
      if(n % 2 == 0 && m <= n / 2)
        cout << "Yes\n";
      else if(m == 0)
        cout << "Yes\n";
      else
        cout << "No\n";
    }                           
}