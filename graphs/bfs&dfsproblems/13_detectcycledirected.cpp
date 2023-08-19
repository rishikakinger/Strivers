#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//first directed graph question 

//dfs

//on the same path, node has to be visited again

bool dfsCheck(int node, vector<int> adj[],int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis)==true)return true;
        }

        //what if node has been visited 
        else if(pathVis[it]){
            return true;
        }
    }


    pathVis[node]=0;
    return false;

}


bool isCycle(int V, vector<int> adj[]){
    int vis[V]={0};
    int pathVis[V]={0};

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfsCheck(i,adj,vis,pathVis)==true)return true;
        }
    }
    return false;

}

//tc same as dfs
//sc is 2n