#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
    
    
    
    Node *insertAtBegining(Node *head, int x) {
       Node* temp=new Node(x);
       if(head==NULL)return temp;
       temp->next=head;

       head=temp;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node* temp=new Node(x);
       if(head==NULL)return temp;
       Node* ptr=head;
       while(ptr->next!=NULL){
        ptr=ptr->next;
       }
       ptr->next=temp;
       return head;
    }