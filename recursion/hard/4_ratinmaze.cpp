
//mouse can move up,down,right,left and can only walk on 1s
//acc to qs, return ans in lexicographic order
//follow DLRU order

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//tc is 4^(n*m)
//sc is m*n

vector<string> findPath(vector<vector<int>>& m,int n){
    vector<string> ans;

    vector<vector<int>> vis(n,vector<int>(n,0));

    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};

    if(m[0][0]==1) solve(0,0,m,n,ans,"",vis,di,dj);


    return ans;

}

void solve(int i,int j,vector<vector<int>> &a,int n, vector<string>& ans,string move, vector<vector<int>>& vis, int di[],int dj[]){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }

    string dir="DLRU";

    for(int ind=0;ind<4;ind++){
        int nexti=i+di[ind];
        int nextj=j+dj[ind];

        if(nexti>0 && nextj>0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1){
            vis[i][j]=1;
            solve(nexti,nextj,a,n,ans,move+dir[ind],vis,di,dj);
            vis[i][j]=0;

        }

    }

     

}
