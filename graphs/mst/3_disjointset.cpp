#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//qs: someone gives you a node x and asks if it belongs to same component as node y
//brute: dfs- takes tc (n+e)

//disjoint set does in const time 
//used in dynamic graphs often

//findparent()
//union()- rank/size 

//rank
//step 1: find ultimate parent of u and v 
//step 2: find rank of ultimate parents
//step 3: connect smaller rank to larger rank always, if equal connect any to any

//rank changes whenever height changes

//to check if x and y belong to the same components, we have to check the ultimate parent. this cna take logN

//path compression 
//rank cannot be reduced 

//tc for union is 4xalpha, close to constant, for find parent and union
//derivation not required 

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