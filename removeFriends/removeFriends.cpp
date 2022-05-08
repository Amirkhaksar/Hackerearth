//Language: c++
//ID: 111
//QLink: https://www.hackerearth.com/problem/algorithm/remove-friends-5/
//Author: mohamammad mahadi abbasi - mahdimma

#include <iostream>
using namespace std;


struct Node
{
public:
	int value = 0;
	Node* next = NULL;
	Node* past = NULL;
};


void append(Node*& tail, int new_data)
{

	Node* new_node = new Node();
	new_node->value = new_data;
	tail->next = new_node;
	new_node->past = tail;
	tail = new_node;
}

void printList(Node*& head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		char endOut = (temp->next == NULL) ? '\n' : ' ';
		std::cout << temp->value << endOut;
		temp = temp->next;
	}
}

void deleteF(Node*& head, int k)
{
	int deleteFriend = 0;
	Node* temp = head;
	while (temp->next != NULL && deleteFriend < k)
	{
		if (temp->value < temp->next->value)
		{
			if (temp->past == NULL)
			{
				head = head->next;
				head->past = NULL;
				temp = temp->next;
			}
			else
			{
				temp->past->next = temp->next;
				temp->next->past = temp->past;
				temp = temp->past;
			}
			deleteFriend++;
		}
		else
		{
			temp = temp->next;
		}
	}
	while (deleteFriend < k)
	{
		head = head->next;
		deleteFriend++;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		Node* head = new Node();
		Node* tail = head;
		int temp;
		cin >> temp;
		head->value = temp;
		for (int j = 1; j < n; j++)
		{
			cin >> temp;
			append(tail, temp);
		}
		if (k != 0)
		{
			deleteF(head, k);
		}
		printList(head);
		delete head;
	}
	return 0;
}