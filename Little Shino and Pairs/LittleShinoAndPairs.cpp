#include <bits/stdc++.h>

using namespace std;

int main() {
    int 
		n, 
		count = 0;

    cin >> n;

    int arr[n];

    stack <int> 
			s,
			s1;

    for(int i = 0; i < n; i++)
    {
     cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
    	while(!s.empty() && arr[i] > arr[s.top()])
			{
				s.pop();
				count = count + 1;
			}
 
			s.push(i);
		}

    for(int i = n - 1; i >= 0; i--)
    {
    	while(!s1.empty() && arr[i] > arr[s1.top()])
			{
					s1.pop();
					count = count + 1;
			}
     
			s1.push(i);
    }

    cout << count << endl;

    return 0;
}