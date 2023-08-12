#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//can use bfs or dfs

//NOTE: vector<int> adj[] is an adjancency list, vector<vector<int>> is adjacency matrix

void dfs(int node, vector<int>adj[],int vis,vector<int>& ls){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis(it)){
            dfs(it,adj,vis,ls);
        }
    }

}


int numProvinces(vector<vector<int>> adj,int V){
    
    //creating an adjacency list out of matrix
    
    vector<int> adj[V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }

    }
    int vis[V+1]={0};
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }

    }



}

//sc (adj list not counted)
//n for vis + n for recursion stack space

//tc is n+v+2e
