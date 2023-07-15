

//RULES:
//1. every column should have a queen
//2. every column should have a queen
//3. none of the queens should attack each other


//in chess, a queen can attack in 8 directions, 4 adjacent and 4 diagonal



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

    solve(0,board,ans,n);
    return ans;

}

void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }

}

bool isSafe(int row,int col, vector<string>& board,int n){
    //only need to check upper left diagonal, lower left diagonal, left
    int duprow=row;
    int dupcol=col;

    //check upper left diagonal
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')return false;
        row--;
        col--;
    }

    //check left
    col=dupcol;
    row=duprow;
    while(col>=0){
        if(board[row][col]=='Q')return false;
        col--;

    }

    //bottom diagonal left
    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q')return false;
        row++;
        col--;
    }
    return true;
}
//isSafe is not efficient, complexity of O(3n)

//alt method: hashing-covered in next file
