
//always consider deepest ancestor


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

//M1: find root to node path for both the nodes, check first non overlapping node, prev is the ans
//uses exra space O(2n) to store path for both nodes


//M2 uses O(n)


Node* lowestCommonAncestor(Node* root, Node* p,Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }

    Node* left=lowestCommonAncestor(root->left,p,q);
    Node* right=lowestCommonAncestor(root->right,p,q);

    if(left==NULL)return right;
    if(right==NULL)return left;

    else{
        return root;
    }
}

//tc is O(n)
//sc is O(n)- skewed tree