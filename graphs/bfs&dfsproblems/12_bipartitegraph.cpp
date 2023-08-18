#include<queue>
#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

//bipartite graph: a graph that can be coloured with 2 colours such that no 2 adjacent nodes have the same colour 

//NOTE: a graph with odd no of nodes in cycle will never be bipartite 
//any linear length graph is bipartite

//dfs


bool dfs(int node, int col, int colour[],vector<int> adj[]){
    colour[node]=col;

    for(auto it: adj[node]){
        if(colour[it]==-1){
            dfs(it,!col,colour,adj);
        }
        else if(colour[it]==col){
            return false;
        }
    }
    return true;

}

bool isBipartite(int V, vector<int> adj[]){
    int colour[V];
    for(int i=0;i<V;i++) colour[i]=-1;

    for(int i=0;i<V;i++){
        if(colour[i]==-1){
            if(dfs(i,0,colour,adj)==false)return false;
        }
    }
    return true;


}

//tc and sc is same as that of dfs
