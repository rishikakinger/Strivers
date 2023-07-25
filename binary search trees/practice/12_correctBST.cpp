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


//brute: do inorder traversal, find correct inorder, and change value
//tc O(n+nlogn+n)
//sc is O(n)


//optimal: 
/*

1.find inorder
2.2 cases: swapped nodes are adjacent or they are not adjacent

tc O(n)
sc O(1)

*/

class Solution{
    private:
    Node* first;
    Node*prev;
    Node*middle;//adjacent violation
    Node* last;

    private:
    void inorder(Node* root){
        if(root==NULL) return;

        inorder(root->left);

        if(prev!=NULL && (root->data < prev->data)){
            if(first==NULL){
                first=prev;
                middle=root;
            }

            else{
                last=root;
            }
        }

        //mark this node as prev
        prev=root;
        inorder(root->right);
    }

    public:

    void recoverTree(Node* root){
        first=middle=last=NULL;
        prev = new Node(INT_MIN);
        inorder(root);

        if(first&&last)swap(first->data,last->data);
        else if(first&&middle) swap(first->data,middle->data);

    }


};
