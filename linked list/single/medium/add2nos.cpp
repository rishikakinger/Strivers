
//only optimal solution exists

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

Node* add2nos(Node* l1, Node* l2){
    Node* dummy=new Node();
    Node* temp=dummy;
    int carry=0;
    

    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;//sum is computed again at every iteration

        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;

        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;


    }


    return dummy->next;

}