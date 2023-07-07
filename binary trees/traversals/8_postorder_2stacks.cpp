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

vector<int> postorder(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)st1.push(root->left);
        if(root->right)st1.push(root->right);


    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }

    return ans;

}
//to do in a single stack, just use reverse fnc