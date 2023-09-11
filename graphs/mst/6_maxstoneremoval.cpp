#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//stones on a 2d plane
//stone can be removed only if it shares same row/col as another stone that has not been removed 
//return max possible stones you can remove 

//look for connected components, all of them can be removed except the last one 

//ans= n-noofcomponents 
//whenevr we talk about connections, disjoint set ds is used 

//rows are nodes in disjoint set 
//columns are also considered as nodes 

//MUG UP 

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

int maxremove(vector<vector<int>>& stones, int n){
    int maxrow=0;
    int maxcol=0;
    for(auto it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }
    DisjointSet ds(maxrow+maxcol+1);
    unordered_map<int,int> stoneNodes;
    for(auto it: stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionBySize(noderow,nodecol);
        stoneNodes[noderow]=1;
        stoneNodes[nodecol]=1;
    }
    int cnt=0;
    for(auto it: stoneNodes){
        if(ds.findUltpar(it.first)==it.first){
            cnt++;
        }
    }
    return cnt;




}