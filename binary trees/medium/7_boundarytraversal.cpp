
//anticlockwise traversal


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

//left boundary excluding leafs

//leaf nodes

//right boundary reversed

bool isLeaf(Node* root){
    return !root->left && !root->right;

}

void addLeftBoundary(Node* root, vector<int>& res){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }

}


void addLeaves(Node* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left)addLeaves(root->left,res);
    if(root->right)addLeaves(root->right,res);

}

void addRightBoundary( Node* root,vector<int>& res){
    Node* curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }

    //reverse array

    for(int i=temp.size()-1;i>=0;--i){
        res.push_back(temp[i]);

    }

}




vector<int> printBoundary(Node* root){
    vector<int> res;
    if(root==NULL)return res;
    if(!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root,res);

    addLeaves(root,res);

    addRightBoundary(root,res);


    return res;

}

//tc is O(n)
//sc is O(n)