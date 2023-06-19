
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


struct Node* deleteNode(struct Node *head,int k)
{
    if (head == NULL)
      return NULL;
     
    if(k==1)
    {
    	Node *temp = head;
    	head = head->next;
    	free(temp);
    	return head;
    }
    else{
    Node *temp = head;
    Node *back;
    k--;
    while(temp!=NULL and k>=1)
    {
    	back=temp;
    	temp = temp->next;
    	k--;
    }
    
    if(temp!=NULL){
    back->next = temp->next;
    free(temp);
    }
    
 
    return head;
    }
}