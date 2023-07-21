
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

//tc is O(n)
//sc is O(1)
//imp^^^^^^

bool isValidBST(Node* root){
    return isValidBST(root,INT_MIN,INT_MAX);

}

bool isValidBST(Node* root, int min, int max){
    if(root==NULL)return true;
    if(root->data >= max || root->data <= min) return false;

    return isValidBST(root->left,min,root->data) && isValidBST(root->right,root->data,max);

}