
//how do i write code like this wtf


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseList(Node* head){
    if(head==NULL)return NULL;

    Node* newhead=head;
    if(head->next!=NULL){//we have subproblems to solve
        newhead=reverseList(head->next);
        head->next->next=head;

    }
    head->next=NULL;
    
    return newhead;
}