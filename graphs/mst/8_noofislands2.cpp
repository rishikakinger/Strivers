#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//online query problem 

//0 is sea, 1 is island 

//return no of components after each query 

//disjoint set 

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

bool isValid(int adjr, int adjc, int n,int m){
    return(adjr>=0 && adjr<n && adjc>=0 && adjc<m);
}



vector<int> numofislands(int n,int m, vector<vector<int>>& operators){
    DisjointSet ds(n*m);
    int vis[n][m];
    memset(vis,0,sizeof vis);
    int cnt=0;
    vector<int> ans;

    for(auto it: operators){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int ind=0;ind<4;ind++){
            int adjr=row+dr[ind];
            int adjc=col+dc[ind];
            if(isValid(adjr,adjc,n,m)){
                if(vis[adjr][adjc]==1){
                    int nodeno=row*m+col;
                    int adjnodeno=adjr*m+adjc;
                    if(ds.findUltpar(nodeno)!=ds.findUltpar(adjnodeno)){
                        cnt--;
                        ds.unionBySize(nodeno,adjnodeno);
                    }
                }
            }

        }
        ans.push_back(cnt);

    }


    return ans;

}