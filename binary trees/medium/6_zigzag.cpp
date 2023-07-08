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

//similar to levelorder traversla, j reverse alternatingly 

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    queue<Node*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight=true;

    while(!nodesQueue.empty()){
        int size=nodesQueue.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            Node* node=nodesQueue.front();
            nodesQueue.pop();

            int index=(leftToRight)? i:(size-i-1);

            row[index]=node->data;
            if(node->left)nodesQueue.push(node->left);
            if(node->right)nodesQueue.push(node->right);

        }
        //after this level

        leftToRight=!leftToRight;
        ans.push_back(row);
    }
    return ans;

}
//tc is O(n)
//sc O(n)
//tc and sc similar to level order