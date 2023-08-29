#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//can move bottom or diagonal right 

//quickest way to reach last row 
//min path sum 

//greedy fails- uniformity 

//no fixed ending point- cant call recursion from back element 

//start from the first 

//no need to check if recursion will go out of bounds diagonally- not possible, try to draw and see 

//tc wihtout dp
//2^(no of elements)- caqn go bottom or diagonal right
//sc will be O(n) stack space

//tc after memoization 
//tc will be no of states o(nxn)
//sc o(n)+o(nxn)

int f(int i,int j, int n, vector<vector<int>>&dp, vector<vector<int>> a){
    if(i==n-1)return a[n-1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int d=a[i][j]+f(i+1,j,n,dp,a);
    int dg=a[i][j]+f(i+1,j+1,n,dp,a);
    return dp[i][j]=min(d,dg);
}
