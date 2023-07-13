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

//last element of postorder is the root of the entire tree for sure


Node* buildTree(vector<int>& inorder,vector<int>& postorder){
    if(inorder.size()!=postorder.size())return NULL;

    map<int,int> hm;

    for(int i=0;i<inorder.size();i++){
        hm[inorder[i]]=i;
    }

    return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);

}


Node* buildTreePostIn(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps, int pe,map<int,int> &hm){
    if(ps>pe || is>ie)return NULL;

    Node* root=new Node(postorder[pe]);

    int inRoot=hm[postorder[pe]];
    int numsLeft=inRoot-is;

    root->left=buildTreePostIn(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,hm);
    root->right=buildTreePostIn(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,hm);

    return root;

}

//tc is O(n)-logn with hashmap
//sc is O(2n)