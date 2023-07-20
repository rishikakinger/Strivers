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


Node* searchBST(Node* root, int data){
    while(root!=NULL && root->data!=data){
        root=data < root->data? root->left:root->right;
    }
    return root;

}

//tc is O(log2n)