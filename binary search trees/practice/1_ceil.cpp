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

//tc is O(log2n)

int findCeil(Node* root, int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key> root->data){
            root=root->right;//cant be the ans
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;

}
//go right easy
//think twice before going left