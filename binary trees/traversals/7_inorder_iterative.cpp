
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

vector<int> inorder(Node* root){
    vector<int> ans;
    if(root==NULL)return;
    stack<Node*> st;
    Node* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;

        }
    }
    return ans;

}

//tc is O(n)
//sc is O(n)