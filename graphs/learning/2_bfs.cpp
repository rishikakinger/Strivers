#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]){
    //for a 0 based indexing graph
    int vis[V]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }

    }
    return bfs;

}

//works for directed and undirected graphs

//sc O(2n)
//tc is O(n*2e)
//for every node n, we visit all degrees (all its neighbours)