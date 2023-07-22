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

//construct a BST from a given preorder traversal

//brute: O(N*N)->inserting n nodes and n places possible

//if you sort preorder, it will turn into inorder
//constructing BT from inorder and preorder
//tc O(nlogn+n) sc O(n)


//optimal
//hard question
//at the worst case, you visit a node 3 times
//tc is O(3n)
//sc is recursion stack space

Node* bstFromPreorder(vector<int>& arr){
    int i=0;
    return build(arr,i,INT_MAX); //only keeping track of upper bound

}

Node* build(vector<int>& arr,int& i,int bound){
    if(i==arr.size() || arr[i]>bound)return NULL; //nothing exists on the left side

    Node* root=new Node(arr[i++]);
    root->left=build(arr,i,root->data);
    root->right=build(arr,i,bound);
    return root;

}