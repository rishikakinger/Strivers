//note: in a path, each node occurs once

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

int maxPathSum(Node* root){
    int maxi=INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int maxPathDown(Node* node,int &maxi){
    if(node==NULL) return 0;
    int left=max(0,maxPathDown(node->left,maxi));//if sum is negative, return 0->imp
    int right=max(0,maxPathDown(node->right,maxi));
    maxi=max(maxi,left+right+node->data);
    return max(left,right)+node->data;

}