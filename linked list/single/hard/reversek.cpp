
//babbar solution best
//tc O(n)
//sc O(n)

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

Node* revkgrps(Node* head, int k){

    int size = 0;
    Node* temp = head;

    while(temp!=NULL){
        temp = temp -> next;
        size++;
    }
    if(size < k)return head;//when number of nodes is not a multiple of k, the left over ones are not to be reversed.


    //base case

    if(head==NULL){
        return NULL;
    }

    //reverse first k nodes

    Node* nex=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count =0;

    while( curr!=NULL && count<k){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        count++;
    }


    //recursion 

    if(nex!=NULL){
        head->next=revkgrps(nex,k);
    }

    return prev;

}