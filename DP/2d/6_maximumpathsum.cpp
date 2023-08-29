#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//variable starting and ending point 

//find max path sum in a matrix from any start point in the first row to any ending point in the last row 

//can move in 3directions- down, diagonal right, diagonal left 

//no greedy-uniformity 

//base cases(in general)- out of bound cases or destination 

//wihtout memoization 
//tc is 3^(n)
//sc is n for stack space 

//memoization 
//tc nxm- no of states at max
//sc is nxm+n

int f(int i,int j, int n,int m, vector<vector<int>>& dp, vector<vector<int>> a){
    if(j<0 || j>=m)return -1e9;
    if(i==0)return a[0][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int s=a[i][j]+f(i-1,j,n,m,dp,a);
    int ld=a[i][j]+f(i-1,j-1,n,m,dp,a);
    int rd=a[i][j]+f(i-1,j+1,n,m,dp,a);
    return dp[i][j]=max(s,max(ld,rd));//how to take max of 3


}

int ans(int n,int m, vector<vector<int>>& dp, vector<vector<int>> a ){
    int maxs=-1e9;
    for(int j=0;j<m;j++){
        int path=f(n-1,j,n,m,dp,a);
        maxs=max(maxs,path);
    }
    return maxs;
}
