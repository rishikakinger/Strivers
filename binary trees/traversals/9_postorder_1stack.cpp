
//mug up kinda code


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

//tc is O(2n)-> worst case is put all right in stack,check all right and pop
//sc isO(n)

vector<int> postorder(Node* root){
    vector<int> ans;
    if(root==NULL)return ans;
    stack<Node*> st;

    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);

                while(!st.empty()&&temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }


            }
            else{
                curr=temp;

            }
        }

    }
    




    return ans;

}