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

bool searchKey(int n, struct Node* head, int key) {
    
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==key)return true;
            temp=temp->next;
        }
        return false;
}