#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//we want to rotten them simultaneously- bfs 
//NOTE: there is a chance that all oranges cannot be rotten



int orangesRotting(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    int time=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        time=max(time,t);
        q.pop();
        for(int i=0;i<4;i++){
            for(int i=0;i<4;i++){

                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({nrow,ncol},t+1);
                    vis[nrow][ncol]=2;
                }

            }

        }
    }

    //check if all are visited 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return time;

}

//sc: queue nxm, visited array nxm

//tc is nxm for first loop, nxmx4 for while 