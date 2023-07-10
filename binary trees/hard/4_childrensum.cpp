
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

//rule is, you can inc the value in the node by any amount, but cant subract
//HARD QUESTION!!


//tc O(n)

//intuition: while going down, inc the nodes value to as much as possible

void changeTree(Node* root){
    if(root==NULL) return;

    int child=0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;

    if(child>=root->data)root->data=child;
    else{
        if(root->left)root->left->data=root->data;
        if(root->right) root->right->data=root->data;

    }
    changeTree(root->left);
    changeTree(root->right);

    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(root->left or root->right)root->data=tot;


}

//tc is O(n)
//sc is O(n)-skewed tree