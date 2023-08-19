#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//topo sort(bfs works on any DAG- directed acyclic graph)

//there can be multiple 

//why dag- directed-obvious, why acyclic- draw ans see, doesnt make sense 
 
void dfs(int node,int vis[], stack<int>& st,vector<int> adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(it,vis,st,adj);
    }
    st.push(node);
}



vector<int> topoSort(int V, vector<int> adj[]){

    int vis[V]={0};
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    

}

//sc n+n
//tc is same as dfs

//intuition: we put in stack those elements who's dfs is done