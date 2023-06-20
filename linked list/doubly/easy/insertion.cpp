
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

void addNode(struct Node *head, int pos, int data)
{
    //creating and storing the new node with data in a pointer.
    struct Node* newnode
		= (struct Node*)malloc(sizeof(struct Node)); 
    struct Node *cur = head;
    newnode->data = data;
    //using another pointer to traverse the linked list till position given.
    for (int i=0; i<pos; i++)    //iterates till one pos behind           
        cur=cur->next;
    
    //if the node next to node at given position is null, we make the next
    //as new node and new node's previous link as this current node.
    if (cur->next==NULL) {                  
        cur->next=newnode;                  
        newnode->prev=cur;
    }
    else {
        
        //storing the next node to current node in link part(next) of new node.
        newnode->next=cur->next; 
        
        //storing new node in link part(next) of current node.
        cur->next=newnode;  
        
        //storing the new node in previous link part(prev) of the node which 
        //was next to current node initially.
        newnode->next->prev=newnode; 
        
        //store the current node in previous link part(prev) of new node.
        newnode->prev=cur;                  
    }
}