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

//if nodes are overlapping, write the smaller value first
//traverse every node and assign verticals and levels to every node

vector<vector<int>> verticalTraversal(Node* root){
    map<int,map<int,multiset<int>>> nodes;//x coord, y coord, no of nodes; stored in a map so order is returned in asc.
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});

    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();

        Node* node=p.first;
        int x=p.second.first, y=p.second.second;
        nodes[x][y].insert(node->data);

        if(node->left) todo.push({node->left,{x-1,y+1}});
        if(node->right) todo.push({node->right,{x+1,y+1}});

    }
    vector<vector<int>> ans;
    for(auto p:nodes){
        vector<int> col;
        for(auto q: p.second){
            col.emplace_back(q.second.begin(),q.second.end());

        }
        ans.push_back(col);
    }

    return ans;

}

//tc O(nlogn)- because of set
//sc is O(n)+O(n)
