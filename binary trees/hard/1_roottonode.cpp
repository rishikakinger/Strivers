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


vector<int> soln(Node* root, int k){
    vector<int> arr;
    if(root==NULL) return arr;
    getPath(root,arr,k);
    return arr;

}


bool getPath(Node* root,vector<int>& arr,int x){
    if(root==NULL) return false;
    arr.push_back(root->data);
    if(root->data==x) return true;

    if(getPath(root->left,arr,x)||getPath(root->right,arr,x))return true;

    arr.pop_back();
    return false;

}