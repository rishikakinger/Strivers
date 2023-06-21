
//need 3 pointers
//in each iteration,
//a,b,c
//break link btw b and c, give it to a and b

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

Node* reverseList(Node* head){
    Node* prev=NULL;
    while(head!=NULL){
        Node* nex=head->next;
        head->next=prev;
        prev=head;
        head=nex;

    }
    return prev;
}
//dont use prev=prev->next, as the link has changed--imp, make it point to pointer only, cant traverse though list anymore