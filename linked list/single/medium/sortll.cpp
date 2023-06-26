
//insertion sort will be O(n^2)
//merge sort 

//find middle of the linked list using slow and fast pointer apporach
//for end of first half of ll, remmeber to point last node to NULL

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


Node* mergeList(Node* head1, Node* head2){

    Node* fh=NULL;//for returning
    Node* ft=NULL;
    while(head1!=NULL && head2!=NULL){

        //if first element

        if(fh==NULL && ft==NULL){

            if(head1->data>head2->data){
                fh=head2;
                ft=head2;
                head2=head2->next;
            }
            else{
                fh=head1;
                ft=head1;
                head1=head1->next;
            }


        }


        //checking for all other elements

        if(head1->data<head2->data){
            ft->next=head1;
            ft=ft->next;//impp

            head1=head1->next;

        }
        else{
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }

    }
    if(head1!=NULL){
        ft->next=head1;//smart
    }

    if(head2!=NULL){
        ft->next=head2;
    }
    return fh;

}





Node* sortList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }//base case as always

    Node* temp=NULL;//prev of slow for making it point to null 
    //basically for separating the linked lists

    Node* fast=NULL;
    Node* slow=NULL;

    while(fast!= NULL && fast->next!=NULL){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    temp->next=NULL;

    Node* l1=sortList(head);//return head of sorted linked list 1
    Node* l2=sortList(slow);//returns head of sorted linked list 2


    return mergeList(l1,l2);


}