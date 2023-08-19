#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//all terminal nodes are safe nodes 

//all paths end at terminal node 

//step 1: reverse all edges 

//step 2: plain topological sort (indegree)

vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    vector<int> adjRev[V];
    int indegree[V]={0};

    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;


}

//tc similar to toposort 
//sc is same + for rev adj