#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//can only move bottom and right 
//minimum path sum 
//greedy wont work - not uniform. its not like values will only increase or only decrease 

//with dp,
//tc is nxm 
//sc is nxm+ recursion stack space is of path length

int f(int i,int j, vector<vector<int>>& dp, vector<vector<int>>a){
    if(i==0 && j==0)return a[0][0];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=a[i][j]+f(i-1,j,dp,a);
    int down=a[i][j]+f(i,j-1,dp,a);
    return dp[i][j]=min(up,down);


}