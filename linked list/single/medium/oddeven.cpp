//solution thought of initially wont work- changes relative order

//note: this soln uses no extra space, think about it

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


Node* divide(int N, Node *head){
    Node* even=NULL;
    Node* odd=NULL;
    Node* e=NULL;
    Node* o=NULL;

    while(head){
        if(head->data%2==0){
            if(even==NULL){
                even=head;
                e=head;
            }
            else{
                e->next=head;
                e=e->next;
            }
        }
        else{
            if(odd==NULL){
                odd=head;
                o=head;

            }
            else{
                o->next=head;
                o=o->next;
            }

        }
        head=head->next;

    }
    //merging
    if(e) e->next=odd;
    if(o) o->next=NULL;

    if(even) return even;
    return odd;


}