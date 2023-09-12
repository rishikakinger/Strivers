#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;

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

//can change at most 1 cell from 0 to 1
//find largest group of connected 1s and return 

//disjoint set 

bool isValid(int newr, int newc, int n){
    return newr>=0 && newr<n && newc>=0 && newc<n;

}



int maxconnection(vector<vector<int>>& grid){

    //step 1: make all components
    int n=grid.size();
    DisjointSet ds(n*n);
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==0) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
                if(isValid(newr,newc,n) && grid[newr][newc]==1){
                    int nodeno=row*n+col;
                    int adjnodeno=newr*n+newc;
                    ds.unionBySize(nodeno, adjnodeno);
                }
            }


        }
    }

    //step: check for every 0(brute)
    int mx=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1)continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            set<int> components;
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
                if(isValid(newr,newc,n)){
                    if(grid[newr][newc]==1){
                        components.insert(ds.findUltpar(newr*n+newc));
                    }

                }
            }
            int sizetot=0;
            for(auto it: components){
                sizetot+=ds.size[it];
            }
            mx=max(mx, sizetot+1);

        }
    }
    //what if a 0 is surrounded by 1 on all sides? wont work in that case
    for(int cellno=0;cellno<n*n;cellno++){
        mx=max(mx,ds.size[ds.findUltpar(cellno)]);
    }
    return mx;


}

//tc is o(n^2)
