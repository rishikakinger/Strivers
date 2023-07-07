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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);

}