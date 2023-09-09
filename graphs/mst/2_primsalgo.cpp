#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//helps you find mst ans well as sum of all edge weights in mst

//requires pq(min heap), visited array, mst array
//mst array stores all edges

//pq stores (weight, node, parent)
//least weight always at the top 

//qs: find sum of weights of edges(no need to carry parent)

int spanningTree(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    int sum=0;
    pq.push({0,0});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;

        if(!vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        for(auto it: adj[node]){
            int adjNode=it[0];
            int edW=it[1];
            if(!vis[adjNode])pq.push({edW,adjNode});
        }
    }
    return sum;



}

//tc 
//while loop runs for E
//pq.top() runs for logE
//for pushing into pq, Ex logE for psuhing 
//elogv+elogv
