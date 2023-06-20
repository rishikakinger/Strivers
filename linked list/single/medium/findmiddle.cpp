
//approach 1: iterate through the linked list to find no of nodes 
//for odd->(n/2)+1 
//for even->n/2
//note:1 based indexing here
//time complexity is O(N+N/2)


//optimal approach: tortoise method
//slow and faster tortoises 
//stop when fast tortoise reaches last node or crosses boundary



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


int getMiddle(Node *head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;

}