
//using a stack

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


vector<int> preorderTraversal(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right)st.push(root->right);
        if(root->left)st.push(root->left);
        

    }

    return ans;

}

//push in stack
//pop
//put right and then left of popped

//tc is O(n)
//sc is O(n)