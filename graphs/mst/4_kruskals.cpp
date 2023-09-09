#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//helps you find mst
//alternative to prims 

//sort all edges acc to weight 
//disjoint set used 

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUltpar(parent[node]);
        //path compression


    }
    void unionByRank(int u, int v){
        //attaching trees
        int ulp_u=findUltpar(u);
        int ulp_v=findUltpar(v);
        if(ulp_u==ulp_v)return;//nothing to do
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    //union by size much more intuitive 
    void unionBySize(int u, int v){
        //attaching trees
        int ulp_u=findUltpar(u);
        int ulp_v=findUltpar(v);
        if(ulp_u==ulp_v)return;//nothing to do
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];            
        }
    }


};









int spanningTree(int V, vector<vector<int>> adj[]){
    vector<pair<int, pair<int,int>>> edges;

    //O(n+e)
    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            int adjNode=it[0];
            int wt=it[1];
            int node=i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    //o(mlogm)
    sort(edges.begin(),edges.end());
    DisjointSet ds(V);
    int mstwt=0;
    //o(mx4xalpha)
    for(auto it: edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUltpar(u)!=ds.findUltpar(v)){
            mstwt+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstwt;

}

