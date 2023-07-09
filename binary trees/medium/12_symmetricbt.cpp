//check if bt is symmetric or not

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

bool isSymmetric(Node* root){
    return root==NULL || isSymmetricHelp(root->left,root->right);

}

bool isSymmetricHelp(Node* left, Node* right){
    if(left==NULL || right==NULL) return left==right;


    if(left->data!=right->data) return false;

    return(isSymmetricHelp(left->left,right->right)&&isSymmetricHelp(left->right,right->left));

}


//tc is O(n)
//sc is O(height of tree)=O(n) for skewed trees