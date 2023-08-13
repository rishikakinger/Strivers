
//undirected graph


#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//using bfs

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node] ){
            if(!vis[adjacentNode]){
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});

            }
            else if(parent!=adjacentNode){
                return true;

            }
        }


    }
    //WHAT IF THE GRAPH IS BROKEN INTO CONNECTED COMPONENTS?

    return false;

}

bool isCycle(int V, vector<int> adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis))return true;
        }

    }
    return false;


}

//tc n*all neighbours = O(n+2e)+O(n) for for loop
//sc o(n)+o(n)
