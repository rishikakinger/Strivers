
//DONT create a new ll, rearrange nodes of the existing bt such that right of node points to next node acc to preorder and all lefts point to NULL
//(rearrange the soln)

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


//recursive solution 

Node* prev=NULL;

void flatten(Node* node, Node* &prev){//pass root node
    if(node==NULL)return;

    flatten(node->right,prev);
    flatten(node->left,prev);

    node->right=prev;
    node->left=NULL;
    prev=node;
}

//tc is O(n)
//sc is O(n)




//iterative solution 

void flattenIterative(Node* root){
    stack<Node*> st;
    st.push(root);

    Node* curr=st.top();
    st.pop();

    if(curr->right){
        st.push(curr->right);
    }

    if(curr->left){
        st.push(curr->left);
    }
    if(!st.empty()){//imp to check
        curr->right=st.top();
    }
    curr->left=NULL;

}
//tc is O(n)
//sc is O(n)


//m3: morris traversal
//preorder

void flattenMorris(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left!=NULL){

            //rightmost in left subtree
            Node* prev=curr->left;
            while(prev->right){
                prev=prev->right;

            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;

        }
        curr=curr->right;
    }

}