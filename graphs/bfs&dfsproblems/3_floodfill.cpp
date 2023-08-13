#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//colour boxes which have same inital value only 

//bfs 

//but how to solve this question using dfs?

void dfs(int row, int col, vector<vector<int>>& ans,vector<vector<int>>& image,int newColor,int delRow[],int delCol[], int iniColor){

    ans[row][col]=newColor;
    //check for neighbours
    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];

        if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);

        }
    }

}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColour){
    int iniColor=image[sr][sc];
    vector<vector<int>> ans=image;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);
    return ans;

}

//tc n*m nodes *4 times traversing
//tc O(n*m)
//sc O(n*m)