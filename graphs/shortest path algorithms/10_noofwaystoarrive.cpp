#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<set>
using namespace std;

//return ALL shortes paths (there can be multiple)

int countPaths(int n, vector<vector<int>>& roads){
    vector<pair<int,int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});

    }
    vector<int> dist(n,1e9);
    vector<int> ways(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0]=0;
    ways[0]=1;
    int mod=(int)(1e9+7);
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode=it.first;
            int edW=it.second;

            if(dis+edW<dist[adjNode]){
                dist[adjNode]=dis+edW;
                pq.push({dis+edW,adjNode});
                ways[adjNode]=ways[node];
            }
            else if(dis+edW==dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
    
}
//tc is elogv
