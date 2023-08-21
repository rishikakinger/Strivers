#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//edge weights may not be 1 
//adj list also stores weights, hence store pairs

//step 1: toposort 
//step 2: take nodes out of stack and relax the edges 

void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int>& st){
    vis[node]=1;
    for(auto it: adj[node]){
        int v=it.first;
        if(!vis[v]){
            topoSort(v,adj,vis,st);
        }
    }
    st.push(node);

}








vector<int> shortestPath(int N,int M, vector<int> edges[]/*array of vectors*/){
    vector<pair<int,int>> adj[N];//array of vector of pairs 
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});

    }
    //find topo sort

    int vis[N]={0};
    stack<int> st;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,st);
        }
    }

    //do the distance thing 
    vector<int> dist(N);
    for(int i=0;i<N;i++)dist[i]=1e9;
    dist[0]=0;//src node

    while(!st.empty()){//O(n+m)
        int node=st.top();
        st.pop();

        for(auto it: adj[node]){
            int v=it.first;
            int wt=it.second;

            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;


}

//tc dfs for toposort+n for stackx all neighbours 
//intuition imp-watch video 
