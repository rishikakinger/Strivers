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

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;

}