//remove duplicates

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



 Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        
        struct Node *p = head;
        struct Node *q = head->next;
        while(p && q)
        {
            if(p->data == q->data)
            {
                p->next = q->next;
                if(q->next) q->next->prev = p;
                q = q->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }