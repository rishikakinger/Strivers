#include<bits/stdc++.h>
#include<iostream>
#include<vector>
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


vector<int> solve(Node* A, int B){
    vector<int> arr;
    if(A==NULL)return arr;
    getPath(A, arr, B);
    return arr;

}

bool getPath(Node* root, vector<int>& arr, int x){
    if(!root)return false;
    arr.push_back(root->data);
    if(root->data==x)return true;
    if(getPath(root->left,arr,x)||getPath(root->right,arr,x))return true;
    arr.pop_back();
    return false;

}






//tc is O(n)
//sc is O(height)