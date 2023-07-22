
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

//brute: store inorder, do a binary search or normal search 
//tc is O(n+n), sc is O(n)

//better: do an inorder traversal, and the first value greater than the given no is your ans
//tc is O(n), sc is O(1)


//optimal: go zig zag, use property of bst
//tc is O(log2n)
//sc is O(1)

Node* inorderSuccessor(Node* root, Node* p){
    Node* successor=NULL;

    while(root!=NULL){

        if(p->data>=root->data){
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }


    }

}