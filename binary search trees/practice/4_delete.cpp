
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

//just rearranging links, no actual deletion of nodes

Node* deleteNode(Node* root, int key){
    if(root==NULL)return NULL;

    if(root->data==key){
        return helper(root);
    }

    Node* dummy=root;

    while(root!=NULL){
        if(root->data > key){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }

    }

    return dummy;

}

Node* helper(Node* tobedel){//returns left of to be del
    if(tobedel->left==NULL){
        return tobedel->right;
    }
    else if(tobedel->right == NULL){
        return tobedel->left;
    }

    Node* rightChild= tobedel->right;
    Node* lastRight=findLastRight(tobedel->left);
    lastRight->right=rightChild;
    return tobedel->left;
}

Node* findLastRight(Node* root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);

}