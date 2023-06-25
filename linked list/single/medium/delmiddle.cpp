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

Node* deleteMid(Node* head)
{
    Node* temp=head;
    int n=0;
    while(temp){
        n++;
        temp=temp->next;
    }
    if(n==1)return head=NULL;
    temp=head;
    int middleprev=(n/2);
    while(middleprev-1){
        middleprev--;
        temp=temp->next;
        
        
        
    }
    temp->next=temp->next->next;
    return head;
    
}