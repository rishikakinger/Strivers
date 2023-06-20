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

    Node* constructDLL(vector<int>& arr) {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=arr[0];
        temp->prev=NULL;
        temp->next=NULL;
        Node* head=temp;
        for(int i=1;i<arr.size();i++){
            Node* curr=(Node*)malloc(sizeof(Node));
            curr->data=arr[i];
            curr->prev=NULL;
            curr->next=NULL;
            curr->prev=temp;
            temp->next=curr;
       
            temp=curr;
            
        }
        return head;
    }