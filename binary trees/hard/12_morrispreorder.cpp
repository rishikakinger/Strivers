//morris traversal

//recursive traversal and iterative take tc O(n) and sc O(n)
//morris traversal takes tc O(n) and sc O(1)
//uses concept of threaded binary tree


//inorder

//once connecting a thread, it is also imp to remove the thread

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



vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            //go to rightmost guy in left subtree

            Node* prev=curr->left;
            while(prev->right&& prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;

            }


        }

    }
    return inorder;


}

vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            //go to rightmost guy in left subtree

            Node* prev=curr->left;
            while(prev->right&& prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;

            }


        }

    }
    return preorder;


}

//tc is O(n)
//sc is O(1)