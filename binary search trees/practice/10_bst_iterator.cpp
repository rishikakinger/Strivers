#include<bits/stdc++.h>
#include<iostream>
#include<stack>
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

//sc should be O(H)
//watch video for intuition

stack<Node*> myStack;

void BSTIterator(Node* root){
    pushAll(root);
}

void pushAll(Node* node){
    for(;node!=NULL;myStack.push(node),node=node->left);

}

bool hasNext(){
    return !myStack.empty();
}

int next(){//always returns elements of inorder 
    Node* tempNode=myStack.top();
    myStack.pop();
    pushAll(tempNode->right);
    return tempNode->data;
}