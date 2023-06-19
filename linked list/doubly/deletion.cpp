
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



    Node* deleteNode(Node *head, int x)
    {
      if(x==1){
          Node* temp=head;
          head=temp->next;
          head->prev=NULL;
          temp->next=NULL;
          free(temp);
          return head;
      }
      if(head==NULL)return NULL;
      
      Node* temp=head;
      x--;
      while(x>=1&&temp->next!=NULL){
          temp=temp->next;
          x--;
      }
      if(temp->next==NULL){
    Node* temp2=temp->prev;
      
      temp2->next=temp->next;
  
      temp->prev=NULL;
      temp->next=NULL;
      free(temp);
      return head;
      }
      Node* temp2=temp->prev;
      Node* temp3=temp->next;
      temp2->next=temp->next;
      temp3->prev=temp2;
      temp->prev=NULL;
      temp->next=NULL;
      free(temp);
      return head;
    }