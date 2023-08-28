#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//same except dead ends exist, and are represented by -1

int countWaysUtil(int i, int j, vector<vector<int> > &dp,vector<vector<int>>a) {

    if(i>=0 && j>=0 && a[i][j]==-1)return 0;

  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp,a);
  int left = countWaysUtil(i,j-1,dp,a);
  
  return dp[i][j] = up+left;
  
}

int countWays(int m, int n,vector<vector<int>> a){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp,a);
    
}
