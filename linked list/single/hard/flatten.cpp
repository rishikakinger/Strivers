#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* mergeLists(Node* a, Node* b){

    Node* temp=new Node(0);
    Node* res=temp;

    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;

        }
        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a) temp->bottom=a;
    else temp->bottom=b;

    return res->bottom;

}

Node* flattenNode(Node* root){

    if(root == NULL || root->next==NULL) return root;

    root->next=flattenNode(root->next);

    return mergeLists(root,root->next);
    
}