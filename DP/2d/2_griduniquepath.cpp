#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

/*
COUNT WAYS SKELETON CODE 

f(){
    base case
        return 0
        return 1
    l=f();
    r=f();
    return l+r;

}


*/

//find total unique paths from top left to bottom right 

//can only move bottom/right 

//tc is 2^(mxn)
//sc is path length = m-1+n-1(rec stack space)


//with memoization,
//tc is nxm (no of states)
//sc is m-1+n-1+(nxm)

int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp);
  int left = countWaysUtil(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}

int countWays(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp);
    
}
