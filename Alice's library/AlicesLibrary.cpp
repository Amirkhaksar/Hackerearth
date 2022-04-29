#include <iostream>
#include <stack> 
#include <queue>

using namespace std;

int main() {
	string s;
	cin >> s;

	stack<char> stack;
	queue<char> queue;

	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '\\' and i + 1 < s.size())
		{		
			while(stack.top() != '/')
			{
				char c = stack.top();
				queue.push(c);
				stack.pop();
			}
			
			stack.pop();
			
			while(!queue.empty())
			{
				char c = queue.front();
				stack.push(c);
				queue.pop();
			}
		}
		else
		{
			stack.push(s[i]);
		}
	}
	
	stack.pop();

	while(!stack.empty())
	{
		cout << stack.top();
		stack.pop();
		
		if(stack.size() == 1) break;
	}
}