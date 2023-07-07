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

    int height(struct Node* node){
        if(node==NULL)return 0;
        return 1+max(height(node->left),height(node->right));
    }

//method 2: use level order traversal- queue req

//worst case for recursive is a skewed tree, for level order is a complete binary tree with all levels filled

int maxDepth(Node* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
        }
        
        return depth;
    }