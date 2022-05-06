/*Language: cpp
ID: 01b722df
QLink:www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/reversed-linked-list-01b722df/
Author: @ellicoder */
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
};

node *head=NULL;

void print() {
    node *tmp=head;
    while(tmp) {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}

node *insert(node *head,int d) {
    node *new_node=new node;
    new_node->data=d;
    new_node->next=NULL;
    if(!head)
        head=new_node;
    else {
        node *tmp=head;
        while(tmp->next)
            tmp=tmp->next;
        tmp->next=new_node;
    }
    return head;
}

node *helper(node *head) {
    stack<node *>stk;
    node *tmp=head,*last=NULL;
    bool flag=false;
    if(tmp->data%2!=0) {
        flag=true;
        head=tmp;
    }
    while(tmp) {
        if(tmp->data%2==0)
            stk.push(tmp);
        else {
            while(!stk.empty()) {
                if(!flag) {
                    flag=true;
                    head=stk.top();
                }
                if(last)
                    last->next=stk.top();
                last=stk.top();
                stk.pop();
            }
            if(last)
                last->next=tmp;
            last=tmp;
        }
        tmp=tmp->next;
    }
    while(!stk.empty()) {
        if(!flag) {
            flag=true;
            head=stk.top();
        }
        if(last)
            last->next=stk.top();
        last=stk.top();
        stk.pop();
    }
    if(last)
        last->next=NULL;
    return head;
}

int main() {
    int n,x;
    cin>>n;
    while(n--) {
        cin>>x;
        head=insert(head,x);
    }
    head=helper(head);
    print();
    return 0;
}