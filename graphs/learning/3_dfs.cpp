#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void dfs(int node, vector<int>adj[],int vis,vector<int>& ls){
    vis[node]=1;
    ls.puhs_back(node);

    for(auto it:adj[node]){
        if(!vis(it)){
            dfs(it,adj,vis,ls);
        }
    }

}




vector<int> dfsOfGraph(int V, vector<int> adj[]){
    int vis[V]={0};
    int start =0;
    vector<int> ls;
    dfs(start, adj,vis,ls);
    return ls;


}

//sc O(n) for vis array+ n recursion stack space+n for adj list

//you traverse any node a single time, for every node, it visits its neightbours 
//tc is O(n)+2*e
