//kth smallest element in a binary search tree

//not sure if the code is correct

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

//brute: dfs/bfs traversal, sort, kth from beg O(n+nlogn), sc of O(n)

//optimal:property-if you write inorder of bst, it is always in sorted order
//keep counter to avoid O(n) storage

//recursive O(n), O(n)
//morris O(n),O(1)


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



Node* getInorder(Node* root,int k){
   
    int counter=0;
    Node* curr=root;
    while(curr!=NULL){

        if(counter==k-1){
            return curr;
        }

        if(curr->left==NULL){
           
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
                
                curr=curr->right;

            }


        }
        counter++;

    }
    return curr;


}