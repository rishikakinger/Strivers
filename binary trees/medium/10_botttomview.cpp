
//if nodes are overlapping, take the right node
//bottom node isnt necessarily leaf node

//last node of each line in vertical order traversal
//replace values in the map

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


vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();

        Node* node=it.first;
        int line=it.second;
        mpp[line]=node->data;

        if(node->left)q.push({node->left,line-1});
        if(node->right)q.push({node->right,line+1});
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }


    return ans;

}