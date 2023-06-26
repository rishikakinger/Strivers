
//merge 2 sorted linked lists 

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

Node* merge2LLs(Node* head1, Node* head2){
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