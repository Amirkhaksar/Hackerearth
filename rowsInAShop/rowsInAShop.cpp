//Language: cpp
//ID: 158
//QLink: https://www.hackerearth.com/problem/algorithm/roses-for-valentine-4a795f72/
//Author: @mahdimma (MohammadMahdi Abbasi)

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int l, r;
	int length;
	Node* next = NULL;
};

int main()
{
	int N, smi;
	cin >> N;
	vector <int> smell;
	cin >> smi;
	smell.push_back(smi);
	Node* head = new Node();
	Node* tail = head;
	(*head).l = 0;
	int maxLength = 0;
	for (int i = 1; i < N; i++)
	{
		cin >> smi;
		smell.push_back(smi);
		if (smell[i] < smell[i - 1])
		{
			(*tail).r = i - 1;
			Node* newNode = new Node();
			(*newNode).l = i;
			(*tail).length = (*tail).r - (*tail).l + 1;
			if (tail->length > maxLength)
			{
				maxLength = tail->length;
			}
			tail->next = newNode;
			tail = newNode;
		}
		if (i == N - 1)
		{
			tail->r = N - 1;
			tail->length = tail->r - tail->l + 1;
			if (tail->length > maxLength)
			{
				maxLength = tail->length;
			}
		}
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		if ((smell[temp->r - 1] < smell[temp->next->l]) || (smell[temp->r] < smell[temp->next->l + 1]))
		{
			int length = temp->length + temp->next->length - 1;
			if (length > maxLength)
			{
				maxLength = length;
			}
		}
		temp = temp->next;
	}
	cout << maxLength;
	return 0;
}