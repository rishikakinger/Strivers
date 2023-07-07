
//diameter of a tree- longest path between ny 2 nodes
//does not need to pass through root

//M1: length of the longest path passing via that node is left height+ right height  
//max of lh and rh amongst nodes is the ans


//tc is O(n^2)



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

int height(Node* root){
        if(root==NULL) return 0;
        int x=height(root->left);
        int y=height(root->right);
        
        return max(x,y)+1;
    }
int maxi=0;

int diameterOfBinaryTree(Node* root) {
        if(root==NULL) return 0;
        
        int x=height(root->left);
        int y= height(root->right);
        
        maxi=max(maxi,x+y+1);//includign that node
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
}


//M2
//tc is O(n)

int findMax(Node* root,int& maxi){//IMP:PASS BY REFERENCE
    if(root==NULL)return 0;

    int lh=findMax(root->left,maxi);
    int rh=findMax(root->right,maxi);
    maxi=max(maxi,lh+rh+1);//including that node 
    return 1+max(lh,rh);
}