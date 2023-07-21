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

//there can be multiple trees formed after inserting, return any 1

//this soln is based on creating a new node and it always being a leaf

Node* insertIntoBST(Node* root, int val){
    if(root==NULL)return new Node(val);
    Node* curr=root;

    while(true){
        if(curr->data<=val){
            //should be inserted on the right
            if(curr->right)curr=curr->right;

            //if it is null, simply insert
            else{
                curr->right=new Node(val);
                break;
            }
        }

        else{
            //its to be inserted on left

            if(curr->left)curr=curr->left;
            else{
                curr->left= new Node(val);
                break;
            }
        }
    }


    return root;

}

//tc is O(log2n)
//keep going right left, the minute you reach NULL, create new node