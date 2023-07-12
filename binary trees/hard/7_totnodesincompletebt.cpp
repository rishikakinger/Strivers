
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

//complete bt: every level, except last is completely filled and all the nodes in the last level are as left as possible

//brute: apply any recursive traversal, tc O(n), O(h), for a complete binary tree height in worst case is logN

//better:divide complete binary tree into subtrees which are complete, no of nodes in a complete bt is (2^h)-1


int findHeightLeft(Node* node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}

int findHeightRight(Node* node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}


int countNodes(Node* root){
    if(root==NULL)return 0;

    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);

    if(lh==rh) return (1<<lh)-1;

    return 1+countNodes(root->left)+countNodes(root->right);

}

//tc is O(logn)^2
//height at any instance is logN
//we are not traversing all nodes, only logN nodes


//sc is O(logn)