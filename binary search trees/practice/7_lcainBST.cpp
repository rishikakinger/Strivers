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

//3 possibilities:
//1. given a node, both lie on the right of it
//2. given a node, both lie on the left of it
//3. given a node, both lie on opposite sides of it

//much easier than LCA

//tc is O(height)
//tc for BT is O(n)


Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root==NULL) return NULL;

    if(root->data< p->data && root->data < q->data){
        return lowestCommonAncestor(root->right,p,q);
    }

    if(root->data > p->data && root->data>q->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;

}