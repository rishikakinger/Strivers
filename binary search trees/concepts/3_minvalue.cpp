#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};



int minValue(Node* root) {
	if(root==NULL)return -1;
	
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}
