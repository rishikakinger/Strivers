#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//cycle detection for DAG is not possible 
//use kahn's 
//toposort has less than n elements 

bool isCyclic(int V, vector<int> adj[]){

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
    return !(topo.size()==V);

}
