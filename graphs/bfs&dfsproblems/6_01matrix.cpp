#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//distance of nearest cell having 1- gfg version

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                //start bfs
                q.push({i,j},0);
                vis[i][j]=1;

            }
            else{
                vis[i][j]=0;

            }
        }
    }

    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        int steps=q.front().second;
        q.pop();
        dis[row][col]=steps;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }

    }
    return dist;

}
//tc nxm
//sc nxm