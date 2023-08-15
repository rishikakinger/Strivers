#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//using dfs

//return true if: cycle detected or can go to next neighbour 
//return false if: dead end 

bool dfs(int node,int parent, int vis[], vector<int> adj[] ){
    vis[node]=1;
    for(auto adjacentnode: adj[node]){
        if(!vis[adjacentnode]){
            if(dfs(adjacentnode,node,vis,adj)==true){
               return true; 
            }
        }
        else if(adjacentnode!=parent)return true;
    }
    return false;



}



bool isCycle(int V,vector<adj> adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true)return true;
        }
    }
    return false;


}

//sc o(n) for recursion + o(n) for vis array(not taking into acc adj list)

//tc o(n+2e)+o(n) for loop 
