#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//shortest path in weighted undirected graph 

//not a qs-concept g32 in strivers

//can be impemented using pq, set 

//pq discussed here (minheap)

//mineheap {dist,node}- sorted acc to dist

//similar to bfs 

//NOTE: DIJKSTRA'S IS NOT APPLICABLE TO GRAPHS WITH NEGATIVE WEIGHTS 

vector<int> dijkstra(int V, vector<vector<int>> adj[],int S){

    //declare min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> dist(V);
    for(int i=0;i<V;i++)dist[i]=1e9;

    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight=it[1];
            int adjNode=it[0];

            if(dis+edgeWeight< dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;

}

//why does dijkstra's not work with negative weights?
/*
-ve is better than zero
same node will infinitely keep being pushed into the queue with a smaller weight each time
for eg. consider 2 nodes with edge weight between them to be -2
0,-2,-4,-6, etc....


*/

//tc elogv-derivation done later 