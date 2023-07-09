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

//level order takes tc O(n), sc O(n)

//recursive soln takes tc O(n), sc is O(height of tree-if skewed then n)
//also, recursive soln is shorter

//approach is reverse preorder- root,right,left

void recursion(Node* root,int level,vector<int>& res){
    if(root==NULL)return;
    if(res.size()==level)res.push_back(root->data);//first element in that level
    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);

}


vector<int> rightSideView(Node* root){
    vector<int> res;
    recursion(root,0,res);
    return res;

}