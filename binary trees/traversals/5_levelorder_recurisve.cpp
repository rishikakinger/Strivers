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

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    //initialise queue
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right)q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);


    }
    return ans;
}

//tc O(n)
//sc O(n)