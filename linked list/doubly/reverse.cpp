
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


Node* reverse(Node* head){
    Node* ptr1=head;
    Node* ptr2=head->next;

    //updating first node
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        
        //move forward
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;

}