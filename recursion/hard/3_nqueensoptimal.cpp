
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    if(n==0) return ans;

    //creating the chessboard
    vector<string> board(n);
    string s(n,'.'); //".......... ntimes"

    for(int i=0;i<n;i++){
        board[i]=s;
    }
    vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
    solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
    return ans;
   
}

void solve(int col,vector<string>& board,vector<vector<string>>& ans,vector<int> &leftRow,vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;

        }
    }

}