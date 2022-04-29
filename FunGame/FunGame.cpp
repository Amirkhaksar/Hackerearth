#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	queue<int> A;
	stack<int> B;
	
	for(int i = 0; i < n; i++)
	{
		int newElement;
		cin >> newElement;

		A.push(newElement);
		B.push(newElement);
	}

	while(true)
	{
		if(B.top() < A.front())
		{
			cout << 1 << " ";
			B.pop();
			
			if(B.size() == 0) break;
		}
		else if(B.top() > A.front())
		{
			cout << 2 << " ";
			A.pop();
			
			if(A.size() == 0) break;
		}
		else
		{
			cout << 0 << " ";
			A.pop();
			B.pop();
			
			if(A.size() == 0) break;
			if(B.size() == 0) break;
		}
	}

	return 0;	
}