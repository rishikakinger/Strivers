//preorder, postorder and inorder in a single traversal
//uses a single stack!
//Node, number

//tc is O(3n)
//sc is O(4n)


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

vector<int> preInPost(Node* root){
    stack<pair<Node*, int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL) return;

    while(!st.empty()){
        auto it=st.top();
        st.pop();

        //if 1 -pre
        //++
        //push left side of tree
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left){
                st.push({it.first->left,1});
            }

        }
        //if 2-in
        //++
        //push right

        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right,1});
            }

        }
        else{
            post.push_back(it.first->data);
        }
    }

}