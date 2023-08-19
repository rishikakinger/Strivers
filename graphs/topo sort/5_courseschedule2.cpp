#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> findOrder(int V,int m,vector<vector<int>> prerequisites){
    //ac to qs, pair is reversed 
    //return any 1 
        //first get adjacency list out of pairs
    vector<int> adj[V];
    for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);

    }
        int indegree[V]={0};

    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }

    }
    
    if(topo.size()==V) return topo;
    return {};

}