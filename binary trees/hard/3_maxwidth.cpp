
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

//width:no of nodes(in the same evel ) btw any 2 nodes

//width depends on level: use level order traversal

//step1: index the tree
//rule for indexing: if the parent is i, the children will be (2i+1) and (2i+2)

//in the worst case, if the tree is skewed 10^5 times then it will overflow


int widthOfBinaryTree(Node* root){
    if(root==NULL) return 0;

    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int curr_id=q.front().second-mmin;
            Node* node= q.front().first;//NOTE: NOT .first()
            q.pop();
            


            //store first and last guys
            if(i==0)first=curr_id;
            if(i==size-1)last=curr_id;
            if(node->left)q.push({node->left,curr_id*2+1});
            if(node->right)q.push({node->right,curr_id*2+2});
             
        }
        ans=max(ans,last-first+1);
    }
    return ans;

}

//tc is O(n)
//sc is O(n)-queue