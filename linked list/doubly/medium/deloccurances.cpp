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

    void deleteAllOccurOfX(struct Node** head_ref, int x) {
           Node* head=*head_ref;
        while(head!=NULL && head->data==x)  head=head->next;
        Node* p=head;
        while(p){
            if(p->data==x){
                if(p->prev)  p->prev->next=p->next;
                if(p->next)  p->next->prev=p->prev;
            }
            p=p->next;
        }
        *head_ref=head;
    }