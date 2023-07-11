
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



//track parents and find node at the same time
Node* bfsToMapParents(Node* root,map<Node*,Node*>&mpp,int start){
    queue<Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty()){
        Node* node=q.front();
        if(node->data==start)res=node;
        q.pop();
        if(node->left){
            mpp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right]=node;
            q.push(node->right);
        }

    }
  return res;
}

int findMaxDistance(map<Node*,Node*>mpp,Node* target){
    queue<Node*> q;
    q.push(target);
    map<Node*,int> vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();
        int fl=0;//burning can happen in any direction
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mpp[node] && !vis[mpp[node]]){
                fl=1;
                vis[mpp[node]]=1;
                q.push(mpp[node]);

            }

        }
        if(fl)maxi++;

    }
    return maxi;
}


int timeToBurnTree(Node* root,int start){
    map<Node*,Node*> mpp;

    //to get node address from int
    Node* target=bfsToMapParents(root,mpp,start);//being efficient
    int maxi=findMaxDistance(mpp,target);
    return maxi;

}

//tc is O(2n)-nlogn including map
//sc is O(n)