#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//shortest path in a binary matrix 

//can visit a cell only once 

//source and destination given 

//4 directions 

//PQ not needed here- weight of going to neighbour is 1 for all, already stored in inc 

//hence additional logn complexity gone 

int shortestPath(vector<vector<int>>& grid, pair<int,int> source,pair<int,int> destination){
    queue<pair<int,pair<int,int>>>q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[source.first][source.second]=0;
    q.push({0,{source.first,source.second}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dis+1<dist[newr][newc]){
                dist[newr][newc]=1+dis;
                if(newr==destination.first && newc==destination.second)return dis+1;
                q.push({1+dis,{newr,newc}});
            }
        }
    }
    return -1;

    

}