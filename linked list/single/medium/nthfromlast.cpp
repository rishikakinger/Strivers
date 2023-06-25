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

int getNthFromLast(Node* head, int k){
    {
    Node* temp=head;
    int n=0;
    while(temp){
        n++;
        temp=temp->next;       
    }
    if(k>n)return -1;
    int front=n-k;
    temp=head;
    while(front){
        temp=temp->next;
        front--;
    }
    return temp->data;
    }

}