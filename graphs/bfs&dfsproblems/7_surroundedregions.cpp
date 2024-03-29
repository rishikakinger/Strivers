#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//observation: if someone is on the boundary, cannot be replaced
//if not connected to a boundary, bound ot be surrounded by x's

//start from boundary 0's and mark them non covertible 
//convert the remaining 0's

void dfs(int row, int col,vector<vector<int>>&vis, vector<vector<int>>&mat){
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();

    //check for top, bottom, right, left


    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
            dfs(nrow,ncol,vis,mat,delrow,delcol);
        }
    }

}









vector<vector<char>> fill(int n,int m,vector<vector<char>> mat){
    vector<vector<int>> vis(n,vector<int>(m,0));

    int delcol[]={-1,0,1,0};
    int delrow[]={0,1,0,-1};

    //traversing column wise
    for(int j=0;j<m;j++){
        //first row
        if(!vis[0][j] && mat[0][j]=='O'){
            dfs(0,j,vis,mat,delrow,delcol);

        }


        //last row 
        if(!vis[n-1][j] && mat[n-1][j]=='O'){
            dfs(n-1,j,vis,mat,delrow,delcol);

        }


    }

    //for first and last column 

    for(int i=0;i<n;i++){
        //first column
        if(!vis[i][0] && mat[i][0]=='O'){
            dfs(i,0,vis,mat,delrow,delcol);

        }


        //last column
        if(!vis[i][n-1] && mat[i][n-1]=='O'){
            dfs(i,n-1,vis,mat,delrow,delcol);

        }


    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j]=='O'){
                mat[i][j]='X';
            }
        }
    }
    return mat;
}
//tc O(mxnx4 for 4 directions)+O(n+m) for loops 
// tc is O(nxm)

//sc O(2nxm)for vis+worst case rec