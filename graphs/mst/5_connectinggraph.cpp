#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//find min no of operatons that will make entire graph connected 
//can remove 1 edge from aywhere and add it elsewhere 

//if there are 5 components, we need 4 edges to connect them

//count extra edges 
//ans=n-1
//if(extraedges>=ans)return else, else return -1

class DisjointSet{
    
public:
vector<int> rank,parent,size;
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

int Solve(int n, vector<vector<int>>& edges){
    DisjointSet ds(n);
    int extra=0;
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        if(ds.findUltpar(u)==ds.findUltpar(v)){
            extra++;

        }
        else{
            ds.unionBySize(u,v);
        }
    }
    int comp=0;
    for(int i=0;i<n;i++){
        if(ds.parent[i]==i)comp++;
    }
    if(extra>=comp-1)return true; 
    return false;
    
}