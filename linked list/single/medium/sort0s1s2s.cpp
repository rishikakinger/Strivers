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


Node* sortList(Node* head){

        
            if(head==NULL || head->next==NULL)return head;

    Node* zero=NULL;
    Node* one=NULL;
    Node* two=NULL;

    Node* zerohead=NULL;
    Node* onehead=NULL;
    Node* twohead=NULL;
    while(head){
        if(head->data==0){
            if( zero==NULL && zerohead==NULL){
                zero=head;
                zerohead=head;
            }
            else{
                zero->next=head;
                zero=zero->next;
            }
            head=head->next;
        }
        else if( head->data==1){
            if( one==NULL && onehead==NULL){
                one=head;
                onehead=head;
            }
            else{
                one->next=head;
                one=one->next;
            }
            head=head->next;

        }
        else{
            if( two==NULL && twohead==NULL){
                two=head;
                twohead=head;
            }
            else{
                two->next=head;
                two=two->next;
            }
            head=head->next;
        }
    }

    if(two)two->next=NULL;
    else if(one) one->next=NULL;
    else zero->next=NULL;

    if(zero && one)zero->next=onehead;
    else if(zero&&two) zero->next=twohead;

    if(one && two) one->next=twohead;

    if(zerohead) return zerohead;
    if(onehead) return onehead;
    if(twohead) return twohead;




}