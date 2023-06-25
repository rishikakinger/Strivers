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


Node* swapNodes(Node* head, int k){
    Node* curr=head;
    for(int i=0;i<k-1;i++){
        curr=curr->next;

    }

    Node* left=curr;
    Node* right=head;
    while(curr->next){//iterate till last node
        curr=curr->next;
        right=right->next;
    }
    //swap left and right data, not pointers- imp
    return head;

}