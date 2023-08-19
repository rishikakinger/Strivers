#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//using bfs- kahn's algorithm 

//once again, topo sort is only valid in DAG's

//step 1: insert nodes with indegree 0 into the queue
//step 2: take node out and reduce indegree of its neighbours
//keep repeating 

vector<int> topoSort(int V, vector<int> adj[]){

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
    return topo;

}

//sc is n for indegree+ n for queue 
//v+e for bfs tc
