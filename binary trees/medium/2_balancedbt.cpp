//a balanced binary tree is one in which, for every node, height(left subtree)-height(right subtree) is either 0 or 1


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


//M1
    int height(struct Node* node){
        if(node==NULL)return 0;
        return 1+max(height(node->left),height(node->right));
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL)return true;
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(!(rh-lh==0||rh-lh==1||rh-lh==-1))return false;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        if(!left||!right) return false;
        return true;
    }


//tc is O(n^2)


//M2
//tc of O(n)

bool isbalanced(Node* root){
    return height1(root)!=-1;
}

int height1(Node* root){
    if(root==NULL) return 0;

    int leftheight=height1(root->left);
    if(leftheight==-1)return -1;
    int rightheight=height1(root->right);
    if(rightheight==-1)return -1;

    if(abs(leftheight-rightheight)>1) return -1; //abs function exists in cpp
    return max(leftheight,rightheight)+1;


}